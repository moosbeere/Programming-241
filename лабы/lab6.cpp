#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// 8. Собственный класс исключений для проверки года рождения
// enum class - перечисление с областью видимости (C++11)
// в отличие от обычного enum, значения не попадают в глобальную область видимости
// доступ: BirthErrorCode::TOO_OLD, а не просто TOO_OLD
enum class BirthErrorCode
{
    TOO_OLD,    // слишком старый год (< 1850)
    TOO_NEW,    // слишком новый год (> текущего)
    NEGATIVE    // отрицательное число
};

// класс наследуется от std::exception - стандартного базового класса для исключений
class BirthYearException : public std::exception
{
private:
    BirthErrorCode code;      // код ошибки из перечисления
    std::string    message;   // текстовое сообщение об ошибке

public:
    explicit BirthYearException(BirthErrorCode c)  // explicit - запрещает неявные преобразования
                                                    // нельзя написать: throw BirthYearException(0);
        : code(c)                                   // инициализация через список инициализации
    {
        switch (code)                               // switch - выбор действия в зависимости от кода
        {
        case BirthErrorCode::TOO_OLD:               // case - метка для конкретного значения
            message = "Что-то не верится...";
            break;                                   // break - выход из switch, иначе выполнится следующий case
        case BirthErrorCode::TOO_NEW:
            message = "Вы ещё не родились";
            break;
        case BirthErrorCode::NEGATIVE:
            message = "Вы ввели отрицательное число!";
            break;
        }
    }

    // переопределение виртуальной функции what() из std::exception
    const char* what() const noexcept override
                              // noexcept - функция гарантированно не выбрасывает исключений
                              // override - явное указание переопределения виртуальной функции
    {
        return message.c_str();  // c_str() - преобразует std::string в C-строку (const char*)
                                 // требуется для совместимости с интерфейсом std::exception
    }

    BirthErrorCode getCode() const noexcept
    {
        return code;
    }
};

int main()
{
    try  // try - блок, в котором могут возникнуть исключения
    {
        // 1–2. Ввод числа 1, 2 или 3
        int num;
        cout << "Введите число (1, 2 или 3): ";
        cin >> num;  // cin >> - оператор извлечения из потока ввода

        if (num == 1)
            cout << "Один" << endl;
        else if (num == 2)  // else if - цепочка условий
            cout << "Два" << endl;
        else if (num == 3)
            cout << "Три" << endl;
        else
            throw std::runtime_error("Некорректное значение");
                              // throw - оператор выбрасывания исключения
                              // std::runtime_error - стандартный класс исключений для ошибок времени выполнения
                              // создаёт объект исключения и передаёт управление в catch блок

        // 3–7. Ввод года рождения (первая версия на стандартных исключениях)
        int year;
        cout << "\nВведите год рождения: ";
        cin >> year;

        const int currentYear = 2025; 

        if (year < 0)
            throw std::runtime_error("Вы ввели отрицательное число!");
        if (year < 1850)
            throw std::runtime_error("Что-то не верится...");
        if (year > currentYear)
            throw std::runtime_error("Вы ещё не родились");

        cout << "Спасибо!" << endl;

        // 8. Та же проверка, но уже через собственный класс исключения
        cout << "\nВведите год рождения ещё раз (проверка через собственное исключение): ";
        cin >> year;

        if (year < 0)
            throw BirthYearException(BirthErrorCode::NEGATIVE);
                              // выбрасываем собственное исключение с кодом ошибки
                              // BirthErrorCode::NEGATIVE - доступ к значению enum class через ::
        if (year < 1850)
            throw BirthYearException(BirthErrorCode::TOO_OLD);
        if (year > currentYear)
            throw BirthYearException(BirthErrorCode::TOO_NEW);

        cout << "Спасибо! (проверка через свой класс исключений)" << endl;
    }
    catch (const BirthYearException& ex)  // catch - блок обработки исключений
                                           // const BirthYearException& - ловим исключение по ссылке
                                           // & - ссылка, не копия (эффективнее)
                                           // const - не изменяем объект исключения
    {
        // Обработка пользовательского исключения (задание 8)
        cout << ex.what() << endl;  // ex.what() - вызов метода, возвращающего описание ошибки
    }
    catch (const std::exception& ex)  // более общий catch для всех исключений, наследующих std::exception
                                       // должен быть после более специфичных catch
    {
        // Обработка стандартных исключений (задания 2, 4–7)
        if (std::string(ex.what()) == "Некорректное значение")
                              // std::string(...) - создание временного объекта string из const char*
                              // == - сравнение строк (перегруженный оператор)
            cout << "Некорректное значение" << endl;
        else if (std::string(ex.what()) == "Что-то не верится...")
            cout << "Что-то не верится..." << endl;
        else if (std::string(ex.what()) == "Вы ещё не родились")
            cout << "Вы ещё не родились" << endl;
        else if (std::string(ex.what()) == "Вы ввели отрицательное число!")
            cout << "Вы ввели отрицательное число!" << endl;
        else
            cout << "Ошибка: " << ex.what() << endl;
    }

    return 0;
}


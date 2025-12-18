#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// 8. Собственный класс исключений для проверки года рождения
enum class BirthErrorCode
{
    TOO_OLD,
    TOO_NEW,
    NEGATIVE
};

class BirthYearException : public std::exception
{
private:
    BirthErrorCode code;
    std::string    message;

public:
    explicit BirthYearException(BirthErrorCode c)
        : code(c)
    {
        switch (code)
        {
        case BirthErrorCode::TOO_OLD:
            message = "Что-то не верится...";
            break;
        case BirthErrorCode::TOO_NEW:
            message = "Вы ещё не родились";
            break;
        case BirthErrorCode::NEGATIVE:
            message = "Вы ввели отрицательное число!";
            break;
        }
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }

    BirthErrorCode getCode() const noexcept
    {
        return code;
    }
};

int main()
{
    try
    {
        // 1–2. Ввод числа 1, 2 или 3
        int num;
        cout << "Введите число (1, 2 или 3): ";
        cin >> num;

        if (num == 1)
            cout << "Один" << endl;
        else if (num == 2)
            cout << "Два" << endl;
        else if (num == 3)
            cout << "Три" << endl;
        else
            throw std::runtime_error("Некорректное значение");

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
        if (year < 1850)
            throw BirthYearException(BirthErrorCode::TOO_OLD);
        if (year > currentYear)
            throw BirthYearException(BirthErrorCode::TOO_NEW);

        cout << "Спасибо! (проверка через свой класс исключений)" << endl;
    }
    catch (const BirthYearException& ex)
    {
        // Обработка пользовательского исключения (задание 8)
        cout << ex.what() << endl;
    }
    catch (const std::exception& ex)
    {
        // Обработка стандартных исключений (задания 2, 4–7)
        if (std::string(ex.what()) == "Некорректное значение")
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


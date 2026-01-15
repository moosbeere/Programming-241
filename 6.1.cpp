#define _CRT_SECURE_NO_WARNINGS // Отключение предупреждений о небезопасных функциях (для localtime)
#include <iostream> // Ввод-вывод
#include <string>   // Работа со строками
#include <ctime>    // Работа со временем

using namespace std;

// Создание собственного класса исключений для года рождения
class BirthYearException : public exception {
public:
    enum ErrorCode { YEAR_TOO_SMALL, YEAR_TOO_LARGE, YEAR_NEGATIVE }; // Коды ошибок
private:
    ErrorCode code; // Переменная для хранения кода ошибки
public:
    BirthYearException(ErrorCode c) : code(c) {} // Конструктор
    const char* what() const noexcept override { // Метод для вывода текста ошибки
        switch (code) {
        case YEAR_TOO_SMALL: return "Что-то не верится...";
        case YEAR_TOO_LARGE: return "Вы ещё не родились";
        case YEAR_NEGATIVE: return "Вы ввели отрицательное число или текст!";
        default: return "Неизвестная ошибка";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // Поддержка русского языка

    // 1. Блок ввода числа 1-3
    while (true) { // Цикл до тех пор, пока ввод не будет верным
        try {
            cout << "Введите число 1, 2 или 3: ";
            int n;
            if (!(cin >> n)) { // Если введено не число
                cin.clear(); // Сброс флага ошибки ввода
                cin.ignore(10000, '\n'); // Очистка буфера от некорректных данных
                throw runtime_error("Ошибка"); // Генерация исключения
            }
            if (n < 1 || n > 3) throw runtime_error("Ошибка"); // Если число вне диапазона

            if (n == 1) cout << "Один" << endl;
            else if (n == 2) cout << "Два" << endl;
            else cout << "Три" << endl;
            break; // Выход из цикла при успешном вводе
        }
        catch (...) { // Ловим любую ошибку из блока try
            cout << "Некорректное значение, попробуйте еще раз." << endl;
        }
    }

    // 2. Блок получения текущего года
    time_t t = time(nullptr); // Получаем системное время
    tm* now = localtime(&t); // Преобразуем в структуру с датой
    int currentYear = now->tm_year + 1900; // Вычисляем текущий год (отсчет идет от 1900)

    // 3. Блок ввода года рождения
    while (true) {
        try {
            cout << "Введите год своего рождения: ";
            int year;
            if (!(cin >> year)) { // Проверка на ввод текста вместо цифр
                cin.clear();
                cin.ignore(10000, '\n');
                throw BirthYearException(BirthYearException::YEAR_NEGATIVE);
            }

            // Проверки логики года
            if (year < 0) throw BirthYearException(BirthYearException::YEAR_NEGATIVE);
            if (year < 1850) throw BirthYearException(BirthYearException::YEAR_TOO_SMALL);
            if (year > currentYear) throw BirthYearException(BirthYearException::YEAR_TOO_LARGE);

            cout << "Спасибо!" << endl;
            break; // Успех
        }
        catch (const BirthYearException& ex) { // Ловим наше специфичное исключение
            cout << ex.what() << endl; // Вывод сообщения об ошибке
        }
    }

    system("pause"); // Задержка консоли
    return 0;
}
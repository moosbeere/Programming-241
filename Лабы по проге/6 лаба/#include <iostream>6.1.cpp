#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 8. Собственный класс исключений для проверки года рождения
class BirthYearException : public exception {
public:
    enum ErrorCode {
        YEAR_TOO_SMALL,
        YEAR_TOO_LARGE,
        YEAR_NEGATIVE
    };
private:
    ErrorCode code;
public:
    BirthYearException(ErrorCode c) : code(c) {}
    ErrorCode getCode() const { return code; }
    const char* what() const noexcept override {
        switch (code) {
            case YEAR_TOO_SMALL: return "Что-то не верится...";
            case YEAR_TOO_LARGE: return "Вы ещё не родились";
            case YEAR_NEGATIVE: return "Вы ввели отрицательное число!";
            default: return "Неизвестная ошибка";
        }
    }
};

int main() {
    // Ввод числа 1, 2, 3 с повтором при ошибке
    while (true) {
        try {
            cout << "Введите число 1, 2 или 3: ";
            int n;
            cin >> n;

            if (!cin) { // на случай если введена строка и cin вошёл в fail state
                cin.clear();
                cin.ignore(10000, '\n');
                throw runtime_error("Некорректное значение");
            }

            switch (n) {
                case 1: cout << "Один" << endl; break;
                case 2: cout << "Два" << endl; break;
                case 3: cout << "Три" << endl; break;
                default: throw runtime_error("Некорректное значение");
            }
            break; // ввод корректен, выходим из цикла
        } catch (const exception&) {
            cout << "Некорректное значение" << endl;
        }
    }

    // Получаем текущий год
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;

    // Ввод года рождения с обработкой и повтором в случае ошибки
    while (true) {
        try {
            cout << "Введите год своего рождения: ";
            int year;
            cin >> year;

            if (!cin) { // если введена строка, а не число
                cin.clear();
                cin.ignore(10000, '\n');
                throw BirthYearException(BirthYearException::YEAR_NEGATIVE);
            }

            if (year < 0) {
                throw BirthYearException(BirthYearException::YEAR_NEGATIVE);
            } else if (year < 1850) {
                throw BirthYearException(BirthYearException::YEAR_TOO_SMALL);
            } else if (year > currentYear) {
                throw BirthYearException(BirthYearException::YEAR_TOO_LARGE);
            } else {
                cout << "Спасибо!" << endl;
                break;
            }
        } catch (const BirthYearException& ex) {
            cout << ex.what() << endl;
        }
    }
}


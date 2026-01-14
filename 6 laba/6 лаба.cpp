#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <clocale>

using namespace std;

// Перечисление для кодов ошибок
enum class YearErrorCode {
    TOO_OLD,
    NOT_BORN_YET,
    NEGATIVE
};

// Класс исключения для года рождения
class BirthYearException : public exception {
private:
    YearErrorCode errorCode;
    
public:
    BirthYearException(YearErrorCode code) : errorCode(code) {}
    
    const char* what() const noexcept override {
        switch(errorCode) {
            case YearErrorCode::TOO_OLD: return "Что-то не верится...";
            case YearErrorCode::NOT_BORN_YET: return "Вы ещё не родились";
            case YearErrorCode::NEGATIVE: return "Вы ввели отрицательное число!";
            default: return "Неизвестная ошибка";
        }
    }
};

// Функция для получения текущего года
int getCurrentYear() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

// Функция для обработки ввода числа 1, 2 или 3
void processNumberInput() {
    int number;
    cout << "Введите число 1, 2 или 3: ";
    cin >> number;
    
    if (number == 1) {
        cout << "Один" << endl;
    } else if (number == 2) {
        cout << "Два" << endl;
    } else if (number == 3) {
        cout << "Три" << endl;
    } else {
        throw invalid_argument("Некорректное значение");
    }
}

// Функция для обработки ввода года рождения
void processBirthYearInput() {
    int birthYear;
    int currentYear = getCurrentYear();
    
    cout << "Введите год рождения: ";
    cin >> birthYear;
    
    // Проверка условий
    if (birthYear < 1850) {
        throw BirthYearException(YearErrorCode::TOO_OLD);
    } else if (birthYear > currentYear) {
        throw BirthYearException(YearErrorCode::NOT_BORN_YET);
    } else if (birthYear < 0) {
        throw BirthYearException(YearErrorCode::NEGATIVE);
    }
    
    cout << "Спасибо!" << endl;
    cout << "Ваш возраст: " << (currentYear - birthYear) << " лет" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    // Часть 1: Ввод числа 1, 2 или 3
    cout << "=== Часть 1 ===" << endl;
    try {
        processNumberInput();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    // Часть 2: Ввод года рождения
    cout << "\n=== Часть 2 ===" << endl;
    try {
        processBirthYearInput();
    } catch (const BirthYearException& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "Неизвестная ошибка" << endl;
    }
    
    return 0;

}

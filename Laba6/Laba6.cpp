#include <iostream>
#include <string>

using namespace std;

// 1. Константа с текущим годом (ставим вручную)
const int CURRENT_YEAR = 2025;

// 2. Класс исключений
class MyException {
private:
    string message;

public:
    MyException(const string& msg) : message(msg) {}
    const string& getMessage() const { return message; }
};

// 3. Функция для ввода числа (пункты 1-2)
void processNumber() {
    int number;
    cout << "Введите число 1, 2 или 3: ";
    cin >> number;

    if (number == 1) {
        cout << "Один" << endl;
    }
    else if (number == 2) {
        cout << "Два" << endl;
    }
    else if (number == 3) {
        cout << "Три" << endl;
    }
    else {
        throw MyException("Некорректное значение");
    }
}

// 4. Функция для ввода года (пункты 3-8)
void processBirthYear() {
    int birthYear;

    cout << "\nВведите год вашего рождения: ";
    cin >> birthYear;

    // Проверки с использованием константы
    if (birthYear < 1850) {
        throw MyException("Что-то не верится...");
    }
    else if (birthYear > CURRENT_YEAR) {
        throw MyException("Вы ещё не родились");
    }
    else if (birthYear < 0) {
        throw MyException("Вы ввели отрицательное число!");
    }
    else {
        cout << "Спасибо!" << endl;
        cout << "Вам примерно " << (CURRENT_YEAR - birthYear) << " лет." << endl;
    }
}

// 5. Главная функция
int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== Программа обработки исключений ===" << endl;
    cout << "Текущий год: " << CURRENT_YEAR << endl;

    // Пункты 1-2
    cout << "\n--- Часть 1-2: Ввод числа ---" << endl;
    try {
        processNumber();
    }
    catch (const MyException& e) {
        cout << "Ошибка: " << e.getMessage() << endl;
    }

    // Пункты 3-8
    cout << "\n--- Часть 3-8: Ввод года рождения ---" << endl;
    try {
        processBirthYear();
    }
    catch (const MyException& e) {
        cout << "Ошибка: " << e.getMessage() << endl;
    }

    // Очистка буфера ввода
    cout << "\nНажмите Enter для выхода...";
    cin.clear();
    cin.ignore(100, '\n');  // Простая очистка

    return 0;
}
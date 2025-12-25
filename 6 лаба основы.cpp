#include <iostream>
#include <string>
using namespace std;

//число 1, 2 или 3
void chislo() {
    cout << "Введите число 1, 2 или 3: ";
    int num;
    cin >> num;

    if (num == 1) {
        cout << "Один" << endl;
    }
    else if (num == 2) {
        cout << "Два" << endl;
    }
    else if (num == 3) {
        cout << "Три" << endl;
    }
    else {
        cout << "Некорректное значение" << endl;
    }
}

//год рождения
void year() {
    cout << "Введите год рождения: ";
    int year;
    cin >> year;

    if (year < 0) {
        cout << "Вы ввели отрицательное число!" << endl;
    }
    else if (year < 1850) {
        cout << "Что-то не верится..." << endl;
    }
    else if (year > 2025) {  
        cout << "Вы ещё не родились" << endl;
    }
    else {
        cout << "Спасибо!" << endl;
    }
}

//простой класс исключения
class MyException {
public:
    string message;

    MyException(string msg) {
        message = msg;
    }
};

//альтернативная версия с простым классом
void proverka() {
    cout << "Введите год рождения (версия с классом): ";
    int year;
    cin >> year;

    try {
        if (year < 0) {
            throw MyException("Вы ввели отрицательное число!");
        }
        else if (year < 1850) {
            throw MyException("Что-то не верится...");
        }
        else if (year > 2024) {
            throw MyException("Вы ещё не родились");
        }

        cout << "Спасибо!" << endl;
    }
    catch (MyException e) {
        cout << e.message << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "=== ПРОСТОЙ ВАРИАНТ (без исключений) ===" << endl;
    chislo();
    year();

    cout << "\n=== ВАРИАНТ С КЛАССОМ (для пункта 8) ===" << endl;
    proverka();

    return 0;
}
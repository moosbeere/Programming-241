#include "ExceptionClass.h"
#include <iostream>

using namespace std;

const char* CustomError::what() const throw() {
    if (code == ErrorCode::Negative) return "Вы ввели отрицательное число";
    else if (code == ErrorCode::Big) return "Вы ещё не родились";
    else if (code == ErrorCode::False) return "Что-то не верится";
}

int main()
{
    setlocale(LC_ALL, "RU");
    int num;
    try {
        cout << "Введите число 1, 2 или 3: ";
        cin >> num;
        if (num == 1) { cout << "один" << endl; }
        else if (num == 2) { cout << "два" << endl; }
        else if (num == 3) { cout << "три" << endl; }
        else throw "Некорректное значение";
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    
    int year;
    try {
        cout << "Введите свой год рождения: ";
        cin >> year;
        if ((year < 1850) && (year > 0)) { throw range_error("Что-то не верится"); }
        else if (year > 2025) { throw logic_error("Вы ещё не родились"); }
        else if (year < 0) { throw exception("Вы ввели отрицательное число"); }
        cout << "Спасибо" << endl;
    }
    catch (exception err) { cout << err.what() << endl; }
    catch (logic_error err) { cout << err.what() << endl; }
    catch (range_error err) { cout << err.what() << endl; }

    // с использованием своего класса исключений
    int new_year;
    try {
        cout << "Введите свой год рождения: ";
        cin >> new_year;
        if ((new_year < 1850) && (new_year > 0)) { throw CustomError(ErrorCode::False); }
        else if (new_year > 2025) { throw CustomError(ErrorCode::Big); }
        else if (new_year < 0) { throw CustomError(ErrorCode::Negative); }
        cout << "Спасибо" << endl;
    }
    catch (CustomError code) { cout << code.what(); }
}
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //полусаем два числа от пользователя
    double num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    //выводим среднее арифметическое
    double average = (num1 + num2) / 2;
    cout << "Среднее арифметическое: " << average << endl;

    //получаем знак операции
    char operation;
    cout << "Введите знак операции (+, -, *, /): ";
    cin >> operation;

    //решение с if-else
    /*
    if (operation == '+') {
        cout << "Результат: " << num1 + num2 << endl;
    }
    else if (operation == '-') {
        cout << "Результат: " << num1 - num2 << endl;
    }
    else if (operation == '*') {
        cout << "Результат: " << num1 * num2 << endl;
    }
    else if (operation == '/') {
        if (num2 != 0) {
            cout << "Результат: " << num1 / num2 << endl;
        }
        else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
    }
    else {
        cout << "Неизвестная операция!" << endl;
    }
    */

    
    //swith case
    switch (operation) {
        case '+':
            cout << "Результат: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Результат: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Результат: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Результат: " << num1 / num2 << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Неизвестная операция!" << endl;
            break;
    }
    

    return 0;
}
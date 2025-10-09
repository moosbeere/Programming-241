#include <iostream>
using namespace std;

int main() {
    
    setlocale(LC_ALL, "RU");
    int num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    
    double average = (num1 + num2) / 2;
    cout << "Среднее арифметическое: " << average << "\n";

   
    char operation;
    cout << "Введите знак операции (+, -, *, /): ";
    cin >> operation;

    double result;

    /*
    // Реализация с использованием условного оператора (закомментировано)
    if (operation == '+') {
        result = num1 + num2;
        cout << "Результат: " << num1 << " + " << num2 << " = " << result << "\n";
    } else if (operation == '-') {
        result = num1 - num2;
        cout << "Результат: " << num1 << " - " << num2 << " = " << result << "\n";
    } else if (operation == '*') {
        result = num1 * num2;
        cout << "Результат: " << num1 << " * " << num2 << " = " << result << "\n";
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Результат: " << num1 << " / " << num2 << " = " << result << "\n";
        } else {
            cout << "Ошибка: деление на ноль!" << "\n";
        }
    } else {
        cout << "Ошибка: неверная операция!" << "\n";
    }
    */

   
    switch (operation) {
    case '+':
        result = num1 + num2;
        cout << "Результат: " << num1 << " + " << num2 << " = " << result << "\n";
        break;
    case '-':
        result = num1 - num2;
        cout << "Результат: " << num1 << " - " << num2 << " = " << result << "\n";
        break;
    case '*':
        result = num1 * num2;
        cout << "Результат: " << num1 << " * " << num2 << " = " << result << "\n";
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Результат: " << num1 << " / " << num2 << " = " << result << "\n";
        }
        else {
            cout << "Ошибка: деление на ноль!" << "\n";
        }
        break;
    default:
        cout << "Ошибка: неверная операция!" << "\n";
        break;
    }

    return 0;
}
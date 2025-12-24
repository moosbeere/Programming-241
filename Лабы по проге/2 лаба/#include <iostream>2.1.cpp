#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    // Часть со средним арифметическим
    double average = (num1 + num2) / 2.0;
    cout << "Среднее арифметическое этих чисел: " << average << endl;

    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << "Сумма: " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Разность: " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Произведение: " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Частное: " << (num1 / num2) << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Неизвестная операция!" << endl;
    }
    return 0;
}

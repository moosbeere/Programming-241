#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    double num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    
    double average = (num1 + num2) / 2;
    cout << "Среднее арифметическое: " << average << endl;

    char operation;
    cout << "Введите знак операции (+, -, *, /): ";
    cin >> operation;

    double result;

    switch (operation) {
    case '+':
        result = num1 + num2;
        cout << "Результат: " << num1 << " + " << num2 << " = " << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << "Результат: " << num1 << " - " << num2 << " = " << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << "Результат: " << num1 << " * " << num2 << " = " << result << endl;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Результат: " << num1 << " / " << num2 << " = " << result << endl;
        }
        else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
        break;
    default:
        cout << "Ошибка: неизвестная операция!" << endl;
        break;
    }

    return 0;

}

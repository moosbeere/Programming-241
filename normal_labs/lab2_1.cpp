#include <iostream>
using namespace std;

int main() {
    // 1. Ввод двух чисел
    double a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    // 2. Среднее арифметическое
    double avg = (a + b) / 2;
    cout << "Среднее арифметическое: " << avg << endl;

    // 3. Ввод знака операции
    char op;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;

    // 4. Сохраняем знак в переменную
    char operation = op;

    // 5. Выполнение операции через условный оператор
    if (operation == '+') {
        cout << "Результат: " << (a + b) << endl;
    } else if (operation == '-') {
        cout << "Результат: " << (a - b) << endl;
    } else if (operation == '*') {
        cout << "Результат: " << (a * b) << endl;
    } else if (operation == '/') {
        if (b != 0)
            cout << "Результат: " << (a / b) << endl;
        else
            cout << "Ошибка: деление на ноль!" << endl;
    } else {
        cout << "Некорректная операция!" << endl;
    }

    /*
    // 6. То же самое с использованием switch-case
    switch (operation) {
        case '+':
            cout << "Результат: " << (a + b) << endl;
            break;
        case '-':
            cout << "Результат: " << (a - b) << endl;
            break;
        case '*':
            cout << "Результат: " << (a * b) << endl;
            break;
        case '/':
            if (b != 0)
                cout << "Результат: " << (a / b) << endl;
            else
                cout << "Ошибка: деление на ноль!" << endl;
            break;
        default:
            cout << "Некорректная операция!" << endl;
    }
    */

    return 0;
}

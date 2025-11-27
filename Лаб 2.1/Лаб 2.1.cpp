#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    cout << "Среднее арифметическое: " << (a + b) / 2 << endl;

    char x;
    cout << "Введите операцию (+ - * /): ";
    cin >> x;

    /*
    if (x == '+') cout << a + b;
    else if (x == '-') cout << a - b;
    else if (x == '*') cout << a * b;
    else if (x == '/') cout << a / b;
    else cout << "Неизвестная операция!";
    */

    switch (x) {
    case '+': cout << a + b; break;
    case '-': cout << a - b; break;
    case '*': cout << a * b; break;
    case '/': cout << a / b; break;
    default: cout << "Неизвестная операция!";
    }

    return 0;
}
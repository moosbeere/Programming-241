

#include <iostream>
#include <string>
using namespace ::std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Задание 1\n";

    double a, b;
    cout << "Введите 2 числа: ";
    cin >> a >> b;
    double c = (a + b) / 2;
    cout << "Среднее арифметическое: " << c << "\n";
    cout << "Введите знак операции: + - *: ";
    string answ;
    cin >> answ;
    if (answ == "+")
        cout << a + b;
    if (answ == "-")
        cout << a - b;
    if (answ == "*")
        cout << a * b;

}


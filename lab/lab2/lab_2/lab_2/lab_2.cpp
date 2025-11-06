// lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    float a;
    int b;
    char c;
    std::cout << "введите два числа числа(через пробел): ";
    cin >> a;
    cin >> b;
    cout << "Среднее арифметическое этих чисел: " << (a + b) / 2 << "\n";
    cout << "Введите операцию, которую хотите сделать(+, -, /, *): ";
    cin >> c;
    /*if (c == "+") {
        cout << a + b;
    }
    else if (c == "-") {
        cout << a - b;
    }
    else if (c == "*") {
        cout << a * b;
    }
    else {
        cout << a / b;
    }*/
    switch (c) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
        default:
            cout << "что-то не то:(";
    }
}
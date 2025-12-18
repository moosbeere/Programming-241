#include <iostream>
#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    int y;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    int sa;
    sa = (x + y)/2;
    std::cout << "Среднее арифметическое: " << sa << "\n";
    char znak;
    std::cout << "Введите знак операции (+, -, *, /): ";
    std::cin >> znak;
    /*if (znak == '+') {
        std::cout << "Результат сложения: " << x + y << std::endl;
    }
    else if (znak == '-') {
        std::cout << "Результат вычитания: " << x - y << std::endl;
    }
    else if (znak == '*') {
        std::cout << "Результат умножения: " << x * y << std::endl;
    }
    else if (znak == '/') {
        if (y != 0) {
            std::cout << "Результат деления: " << x / y << std::endl;
        }
        else {
            std::cout << "Ошибка: деление на ноль невозможно." << std::endl;
        }
    }
    else {
        std::cout << "Ошибка: неверный знак операции." << std::endl;
    }
    return 0;*/
    switch (znak) {
    case '+':
        std::cout << "Результат сложения: " << x + y << std::endl;
        break;
    case '-':
        std::cout << "Результат вычитания: " << x - y << std::endl;
        break;
    case '*':
        std::cout << "Результат умножения: " << x * y << std::endl;
        break;
    case '/':
        if (y != 0)
            std::cout << "Результат деления: " << x / y << std::endl;
        else
            std::cout << "Ошибка: деление на ноль невозможно." << std::endl;
        break;
    default:
        std::cout << "Ошибка: неверный знак операции." << std::endl;
}
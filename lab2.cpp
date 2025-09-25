#include <iostream>

int main() {
    double firstNumber = 0.0;
    double secondNumber = 0.0;

    std::cout << "Введите два числа: ";
    if (!(std::cin >> firstNumber >> secondNumber)) {
        std::cerr << "Ошибка ввода чисел" << std::endl;
        return 1;
    }

    const double arithmeticMean = (firstNumber + secondNumber) / 2.0;
    std::cout << "Среднее арифметическое: " << arithmeticMean << std::endl;

    std::cout << "Введите операцию (+, -, *, /): ";
    char operation = '+';
    if (!(std::cin >> operation)) {
        std::cerr << "Ошибка ввода операции" << std::endl;
        return 1;
    }

    // Вариант 1: через if-else
    /*
    if (operation == '+') {
        std::cout << "Результат: " << (firstNumber + secondNumber) << std::endl;
    } else if (operation == '-') {
        std::cout << "Результат: " << (firstNumber - secondNumber) << std::endl;
    } else if (operation == '*') {
        std::cout << "Результат: " << (firstNumber * secondNumber) << std::endl;
    } else if (operation == '/') {
        if (secondNumber == 0.0) {
            std::cerr << "Ошибка: деление на ноль" << std::endl;
            return 1;
        }
        std::cout << "Результат: " << (firstNumber / secondNumber) << std::endl;
    } else {
        std::cerr << "Неизвестная операция" << std::endl;
        return 1;
    }
    */

    // Вариант 2: через switch-case
    switch (operation) {
        case '+':
            std::cout << "Результат: " << (firstNumber + secondNumber) << std::endl;
            break;
        case '-':
            std::cout << "Результат: " << (firstNumber - secondNumber) << std::endl;
            break;
        case '*':
            std::cout << "Результат: " << (firstNumber * secondNumber) << std::endl;
            break;
        case '/':
            if (secondNumber == 0.0) {
                std::cerr << "Ошибка: деление на ноль" << std::endl;
                return 1;
            }
            std::cout << "Результат: " << (firstNumber / secondNumber) << std::endl;
            break;
        default:
            std::cerr << "Неизвестная операция" << std::endl;
            return 1;
    }

    return 0;
}


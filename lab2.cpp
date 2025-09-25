// Lab 2: Read two numbers and print their arithmetic mean
#include <iostream>

int main() {
    double firstNumber = 0.0;
    double secondNumber = 0.0;

    std::cout << "Введите два числа: ";
    if (!(std::cin >> firstNumber >> secondNumber)) {
        std::cerr << "Ошибка ввода" << std::endl;
        return 1;
    }

    const double arithmeticMean = (firstNumber + secondNumber) / 2.0;
    std::cout << "Среднее арифметическое: " << arithmeticMean << std::endl;

    return 0;
}


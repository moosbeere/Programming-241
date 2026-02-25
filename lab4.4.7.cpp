#include "lab4.4.4.h"
#include <iostream>

int MyMath::callCount = 0;

int MyMath::Add(int a, int b) {
    callCount++;
    return a + b;
}

int MyMath::Sub(int a, int b) {
    callCount++;
    return a - b;
}

int MyMath::Mult(int a, int b) {
    callCount++;
    return a * b;
}

double MyMath::Div(int a, int b) {
    callCount++;
    if (b == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    return static_cast<double>(a) / b;
}
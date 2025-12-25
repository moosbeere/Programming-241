#include "mymath.h"


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

float MyMath::Div(int a, int b) {
    callCount++;
    if (b != 0) {
        return static_cast<float>(a) / b;
    }
    return 0.0f;
}
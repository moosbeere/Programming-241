#include "MyMath.h"

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

float MyMath::Div(float a, float b) {
    callCount++;
    return a / b;
}

#include "MyMath.h"

int MyMath::Add(int a, int b) {
    staticMethodCount++;
    return a + b;
}
int MyMath::Sub(int a, int b) {
    staticMethodCount++;
    return a - b;
}
int MyMath::Mult(int a, int b) {
    staticMethodCount++;
    return a * b;
}
int MyMath::Div(int a, int b) {
    staticMethodCount++;
    return a / b;
}
int MyMath::getStaticCount() { return staticMethodCount; }


int MyMath::staticMethodCount = 0;
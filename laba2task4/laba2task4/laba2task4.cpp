#include <iostream>
#include "static_function.h"
#include "static_function.cpp"

using namespace std;
using namespace StaticUtils;

int main() {
    cout << "Демонстрация работы со статической переменной:" << endl;

    cout << "\nПервый вызов с числом 5:" << endl;
    staticFunction(5);

    cout << "\nВторой вызов с числом 10:" << endl;
    staticFunction(10);

    cout << "\nТретий вызов с числом 3:" << endl;
    staticFunction(3);

    return 0;
}
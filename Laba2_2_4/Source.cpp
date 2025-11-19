#include <iostream>
#include "MyMath.h"

using namespace std;

void MyMath::Staticfoo(int number) {
    static int staticVar = 0; 

    // Вывод суммы переданного числа и статической переменной
    cout << "Переданное число: " << number << ", Статическая переменная: " << staticVar;
    cout << ", Сумма: " << (number + staticVar) << endl;

    // Присвоение статической переменной значения переданного числа 
    staticVar = number;
}
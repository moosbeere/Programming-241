#include <iostream>
#include "func.h"

using namespace std;
using namespace MySpace;

//#define SUM(a, b) ((a) + (b))
//
//void func(int num) {
//    static int stat = 0;
//    cout << endl << "Сумма аргумента и статической переменной = " << SUM(stat, num);
//    stat = num;
//}

int main()
{
    setlocale(LC_ALL, "Ru");
    cout << "Первый вызов функции с числом 10: ";
    func(10);
    cout << "\nВторой вызов функции с числом 20: ";
    func(20);
    cout << "\nТретий вызов функции с числом 100: ";
    func(100);
    cin.get();
}
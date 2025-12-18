// lab2_44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "header.h"
#include <iostream>
using namespace std;
#define calculate(x,y) x+y;

int main()
{
    head::printSum(10);
    cout << calculate(10, 5);
}
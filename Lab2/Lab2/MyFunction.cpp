#include "MyFunction.h"
#include <iostream>
void MyFunc::myFunction(int num)
{
    static int staticVar = 0;
    //Вывод суммы и обновеление статической переменной
    std::cout << staticVar + num << std::endl;
    staticVar = num;
}

#include <iostream>
#include "static_function.h"

using namespace std;

// Макрос для вычисления суммы двух чисел
#define SUM(x, y) ((x) + (y))

// Функция со статической переменной в пространстве имён
void StaticUtils::staticFunction(int number) {
    static int staticVar = 0; // статическая переменная с начальным значением 0
    
    // Используем макрос SUM для вычисления суммы
    int sum = SUM(staticVar, number);
    cout << "Сумма статической переменной (" << staticVar << ") и переданного числа (" << number << ") = " << sum << endl;
    
    // Присваиваем статической переменной значение переданного числа
    staticVar = number;
    cout << "Статическая переменная теперь равна: " << staticVar << endl;
}

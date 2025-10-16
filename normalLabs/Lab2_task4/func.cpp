#include <iostream>
#include "func.h"

using namespace std;

#define SUM(a, b) ((a) + (b))

namespace MySpace {
    void func(int num) {
        static int stat = 0;
        cout << endl << "Сумма аргумента и статической переменной = " << SUM(stat, num);
        stat = num;
    }
}
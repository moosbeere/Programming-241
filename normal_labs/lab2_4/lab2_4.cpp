#include "static_func.h"
#include <iostream>

int main() {
    MyFuncNS::staticFunc(5);
    MyFuncNS::staticFunc(10);
    MyFuncNS::staticFunc(3); 

    #define SUM(a, b) ((a) + (b))
    std::cout << "SUM(4, 7) = " << SUM(4, 7) << std::endl;

    return 0;
}

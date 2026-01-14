#include "static_func.h"
#include <iostream>

namespace io = std;

namespace MyFuncNS {

void staticFunc(int x) {
    static int prev = 0;  
    io::cout << "Сумма: " << x + prev << io::endl;
    prev = x;  
}

}

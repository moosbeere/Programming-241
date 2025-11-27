#include <iostream>
#include "2.h"

using namespace std;

namespace MySpace {

    void staticFunc(int x) {
        static int y = 0;

        cout << "Сумма: " << (x + y) << endl;

        y = x;
    }

}

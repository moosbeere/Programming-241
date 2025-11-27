#include <iostream>
#include "2.h"

using namespace std;
using namespace MySpace;

#define SUM(a, b) ((a) + (b))

int main() {
    setlocale(LC_ALL, "RU");

    staticFunc(10);
    staticFunc(5);
    staticFunc(20);

    cout << "SUM(3, 7) = " << SUM(3, 7) << endl;

    return 0;
}

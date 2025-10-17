#include "zadheader.h"
#include <iostream>

using namespace std;

void zad4(int n) {
    static int stat = 0;
    cout << n + stat << " " << stat << "\n";
    stat = n;
}
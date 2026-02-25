#include "lab2.4.2.h"
#include <iostream>

using namespace std;

namespace MyFunctions {
void staticFunc(int num) {
  static int s = 0;

  cout << "s = " << s << ", num = " << num << ", сумма = " << (s + num) << endl;

  s = num;
}
}

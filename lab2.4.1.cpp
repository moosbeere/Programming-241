#include "lab2.4.2.h"
#include <iostream>

using namespace std;

#define SUM(a, b) ((a) + (b))

int main() {
  MyFunctions::staticFunc(5);
  MyFunctions::staticFunc(10);
  MyFunctions::staticFunc(3);
  MyFunctions::staticFunc(8);

  int x = 5, y = 10;
  cout << "SUM(" << x << ", " << y << ") = " << SUM(x, y) << endl;

  double a = 2.5, b = 3.7;
  cout << "SUM(" << a << ", " << b << ") = " << SUM(a, b) << endl;

  cout << "SUM(" << x << "+1, " << y << "*2) = " << SUM(x + 1, y * 2) << endl;

  return 0;
}

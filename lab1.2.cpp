#include <iostream>

using namespace std;

int main() {
  int i = 150;

  float f = 15.933f;

  unsigned char s = 250;

  cout << "i = " << i << endl;
  cout << "f = " << f << endl;
  cout << "s = " << static_cast<int>(s) << endl;

  unsigned char day = 27;
  string month = "Апрель";
  unsigned short year = 2006;

  cout << "Моя дата рождения: " << static_cast<int>(day) << " " << month << " "
       << year << " года" << endl;

  const double PI_CONST = 2.3;
  const string OS_CONST = "WINDOWS";

  cout << PI_CONST << " " << OS_CONST << endl;

  return 0;
}

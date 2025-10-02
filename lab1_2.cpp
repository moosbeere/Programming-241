#include <iostream>
using namespace std;

int main()
{
    int a = 150;
    float b = 15.933;
    short  c = 250;
    setlocale(LC_ALL, "RU");
    cout << "First string\n";
    cout << "Первая строка\nВторая строка\n";
    cout << "Спецсимволы \"\\\"\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    short  d = 14;
    short  m = 06;
    short  y = 2007;
    std::cout << d << "." << m << "." << y << "\n";
    float s = 2.3;
    string o = "WINDOWS";
    std::cout << s << " " << o << "\n";

}
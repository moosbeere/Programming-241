#include <iostream> //подключаю библиотеку
using namespace std; //урощаю код
int main() //функция мэйн
{//начало тела функции

    setlocale(LC_ALL, "RU");
    cout << "First string\n";
    cout << "Первая строка\nВторая строка\n";
    cout << "Спецсимволы \"\\\"\n";
    int a = 150;
    float b = 15.933;
    short  c = 250;
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    short  d = 17;
    short  m = 07;
    short  y = 2006;
    std::cout << d <<"." << m << "." << y << "\n";
    float s = 2.3;
    string o = "WINDOWS";
    std::cout << s << " " << o << "\n";

}

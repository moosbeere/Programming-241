// lab1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int n = 150;
float n1 = 15.933;
short n2 = 250;

int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "Hello World!\n";
    cout << "n = " << n << "\n";
    cout << "n1 = " << n1 << "\n";
    cout << "n2 = " << n2 << "\n";
    short den = 2;
    string mesac = "март";
    short god = 2006;
    cout << "Моя дата рождения: " << den << " " << mesac << " " << god;
}
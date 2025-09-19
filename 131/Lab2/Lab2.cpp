// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //string name;
    //cout << "Введите имя: ";
    //cin >> name;
    //cout << "Привет, " << name << endl;

    //cout << "Enter x: ";
    //int x;
    //cin >> x;
    //cout << "Enter y: ";
    //int y;
    //cin >> y;
    //cout << (x + y) << endl;

    //int a;
    //cout << "Hello World!\n";
    //cin >> a;
    //a = a + a; //a+=a
    //a++; //a = a + 1
    //a--; //a = a - 1
    //cout << a;

    bool b = true;
    if (b) {
        cout << "ok" << endl;
    }
    else if (!b) {
        cout << "no" << endl;
    }
    else cout << "!\n";

    //int x = 7;
    //if (x < 10) x = 10;
    //else x = 5;

    //x = (x < 10) ? 10 : 5;

    //int z;
    //cout << "Enter number: ";
    //cin >> z;
    //switch (z) {
    //case(1): cout << "enter one\n";
    //    break;
    //case(2): cout << "enter two\n";
    //    break;
    //default: cout << "i don`t know";
    //}

    //for (int i = 1; i < 10; i++) {
    //    cout << "Hello" << i << "\n";
    //}
    //cout << i; ошиибка обращения к локальной области видимости цикла
    int i = 1;
    while (i <= 5) {
        cout << i << "\n";
        i++;
        if (i == 3) continue;
        if (i == 4) break;
    }
    //do {
    //    cout << i << endl;
    //    i++;
    //} while (i <= 10);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

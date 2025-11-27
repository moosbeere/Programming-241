// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void sumtab(int* begin, int* end) {
    for (int* i = begin; i < end; i++) {
        cout << *i << ' ';
    }
}

int main()
{
    bool a = true;
    cout << a << endl;
    int tab[] = { 5, 8, 9, 7 };
    sumtab(tab, std::end(tab));


    for (int* y = tab; y <= &tab[3]; y++) {
        std::cout << *y << "\n";
    }
    cout << &tab[3] << endl;

    //setlocale(LC_ALL, "russian");
    //const int P = 3.14;
    //int a;
    //float f;
    //double d;
    //char s;
    //short min;
    ////long long long long max;

    ////s = 's';
    ////cout << s;
    //cout << "Привет мир\\!\n";
    ////cin >> a;
    ////cout << a;

    //int x = 5;
    //int y = x<<1;
    //int z = x>>1;
    //cout << y << "\n";
    //cout << z << "\n";
    //bool b1 = true;
    //cout << !b1;
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

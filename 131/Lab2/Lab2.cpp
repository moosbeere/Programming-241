// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Windows.h"
using namespace std;

void sayHello();
void sayHello(string name);
void sayName(string name);
int sum(int x, int y, bool pr = false);


int main()
{
    //function
    sum(4, 6, true);
    sayHello();
    sayHello("mira");
    sayName("olga");

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
        //cout << "ok" << endl;
    }
    else if (!b) {
        //cout << "no" << endl;
    }
    //else cout << "!\n";

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
        //cout << i << "\n";
        i++;
        if (i == 3) continue;
        if (i == 4) break;
    }
    //do {
    //    cout << i << endl;
    //    i++;
    //} while (i <= 10);

    int numbers[5];
    numbers[0] = 45;
    numbers[1] = 54;
    numbers[2] = 76;
    numbers[3] = 65;
    numbers[4] = 78;
    int len = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < len; i++) {
        //cout << i << ": " << numbers[i] << endl;
    }
    int numbers2[4] = { 2,5,8,3 };
    int sum = 0;
    for (auto e : numbers2) { // если заранее неизвестен тип данных элементов массива
        sum += e;// sum = sum + e
    }

    int numbers3[] = { 2,5,8,3,7 };

    for (int e : numbers3) {
        sum += e;// sum = sum + e
    }
    //cout << sum << endl;

    //многомерные массивы
    //int array[3][2] = { {2,5}, {6,8}, {98, 7} };
    //for (auto &e : array) {
    //    for (int i : e) {
    //        cout << i << ", ";
    //    }
    //    cout << endl;
    //}
    //cout << array[0][0] << endl;

    //for (int i = 0; i < 3; i++) {
    //    for (int j = 0; j < 2; j++) {
    //        for (int j = 0; j < 2; j++) {
    //        //cout << array[i][j] << ", ";
    //    }
    //    //cout << endl;
    //}

    //ссылки
    int x = 14;
    int& y = x;
    cout << y << endl;
    y = 15;
    cout << x << endl;
}

void sayHello() {
    cout << "Hello, world!\n";
}

void sayName(string name) {
    cout << name << "\n";
}

void sayHello(string name) {
    cout << "Hello, " << name << endl;
}

int sum(int x, int y, bool pr = false) {
    int s = x + y;
    if (pr) cout << s << endl;
    return s;
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

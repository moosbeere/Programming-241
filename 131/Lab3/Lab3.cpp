// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const float PI = 3.14f;
const float G = 9.8f;

int main()
{
    //указатели и коснтанты
    //float* pPI = &PI; ошибка
    const float* pPI = &PI;
    cout << pPI << " = " << *pPI << endl;
    const float* pG = &G;
    cout << pG << " = " << *pG << endl;

    int x = 10;
    int y = 15;
    const int *pX = &x;
    cout << pX << " = " << *pX << endl;
    //*pX = 30; ошибка изменения значения на который указывает константный указатель
    pX = &y;// можем присвоить ему новый адрес
    cout << pX << " = " << *pX << endl;





    //указатели
    //int a = 10;
    //int* pointer = &a;
    //cout << pointer << endl;
    ////cout << *pointer << endl;
    ////*pointer = 25;
    ////cout << a << endl;
    //pointer++;
    //cout << pointer << endl;
    //cout << *pointer << endl;
    //pointer--;
    //cout << pointer << endl;
    //cout << *pointer << endl;
    //cout << (*pointer * 2) << endl;

    //int array[] = { 20,5,3,87 };
    //cout << *array << endl;
    //for (int i = 0; i < 4; i++) {
    //    cout << *(array + i) << ", ";
    //}cout << endl;

    //for (int* pntr = array; pntr < &array[4]; pntr++) {
    //    cout << *pntr << ", ";
    //}cout << endl;

    //int mArray[3][2] = { {1,2}, {3,4}, {5,6} };
    //int row = sizeof(mArray) / sizeof(mArray[0]);
    //int col = sizeof(mArray[0]) / sizeof(mArray[0][0]);
    //int* end = mArray[0] + col * row;
    //for (int* pnt = mArray[0], i = 1; pnt < end; pnt++, i++) {
    //    cout << *pnt << ", ";
    //    if (i % 2 == 0) cout << endl;
    //}cout << endl;

    //char chars[] = "Hello";
    //cout << (void*)chars << endl;
    //char* pchar = chars;
    //cout << pchar << endl;
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

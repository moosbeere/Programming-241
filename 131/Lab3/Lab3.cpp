// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const float PI = 3.14f;
const float G = 9.8f;

void separator() {
    cout << "---------------------\n";
}

void printArray(int array[], int length) {
    cout << *array;
    separator();
    int leng = sizeof(array) / sizeof(array[1]);
    cout << leng << endl;
    separator();
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }cout << endl;
    //for(int elem : array) {
    //    cout << elem << ", ";
    //} ошибка применения цикла foreach при передачи массива в функцию
}

void printArray(int* begin, int* end) {
    for (int* p = begin; p < end; p++) {
        cout << *p << ", ";
    }cout << endl;
}

const int cols = 2;
void printArray2(int(*array)[cols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << ", ";
        }cout << endl;
    }
}

void function1() {
    cout << "Function1" << endl;
}

void function2() {
    cout << "Function2" << endl;
}

float add(float a, float b) {
    return a + b;
}

float sub(float a, float b) {
    return a - b;
}

bool compare1(int z, int v) {
    return z > v;
}

bool compare2(int z, int v) {
    return z < v;
}

int getMaxOrMin(int array[], int length, bool (*compare)(int, int)) {
    int maxOrMin = array[0];
    for (int i = 1; i < length; i++) {
        if (compare(array[i], maxOrMin)) maxOrMin = array[i];
    }
    return maxOrMin;
}

void numberPositive() {
    cout << "+\n";
}

void numberNegative() {
    cout << "-\n";
}

void (*function(int x))() {
    if (x < 0) return numberNegative;
    else return numberPositive;
}

int* test() {
    return new int(6);
}

int main()
{
    //динамические объекты
    int* pc1 = new int(5);
    cout << pc1 << "=" << *pc1 << endl;
    delete pc1;
    int* pc2 = test();
    cout << pc2 << "=" << *pc2 << endl;
    delete pc2;

    int* array = new int[]{3, 7, 2};

    for (int* i = array; i < array + 4; i++) {
        cout << *i << ", ";
    }
    delete[] array;



    //указатели на функции

    /*void (*test)() = function(-5);
    test();
    test = function(6);
    test();


    void (*pf)();
    pf = function1;
    pf();
    pf = function2;
    pf();

    void (*pfs[])() = { function1, function2 };
    pfs[0]();
    pfs[1]();
    float (*operation)(float, float);
    operation = add;
    cout << operation(2, 3) << endl;
    operation = sub;
    cout << operation(2, 3) << endl;
    int array[] = { 3,7,2,89,3,7 };
    int length = sizeof(array) / sizeof(array[0]);
    cout << getMaxOrMin(array, length, compare2);*/



    //функции и массивы
    /*int array[] = { 3,7,2,89,3,7 };
    int length = sizeof(array) / sizeof(array[0]);
    printArray(array, length);
    printArray(begin(array), end(array));
    int array2[3][2] = { {3,5},{3,8}, {98,33} };
    printArray2(array2, 3);*/

    //указатели и коснтанты
    //float* pPI = &PI; ошибка
    /*const float* pPI = &PI;
    cout << pPI << " = " << *pPI << endl;
    const float* pG = &G;
    cout << pG << " = " << *pG << endl;

    int x = 10;
    int y = 15;
    const int *pX = &x;
    cout << pX << " = " << *pX << endl;*/
    //*pX = 30; ошибка изменения значения на который указывает константный указатель
    //pX = &y;// можем присвоить ему новый адрес
    //cout << pX << " = " << *pX << endl;

    //int z = 20;
    //int* const pntZ = &z;
    //cout << pntZ << " = " << *pntZ << endl;
    //*pntZ = 65;
    //cout << pntZ << " = " << *pntZ << endl;
    ////pntZ = &x; ошибка попытки смены адреса указателя

    //int m = 40;
    //const int* const pntM = &m;
    //cout << pntM << " = " << *pntM << endl;
    //*pntM = 65; ошибка смены значения константного указателя
    //pntM = &z; ошибка смены адреса константного указателя










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

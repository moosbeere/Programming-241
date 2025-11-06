#include <iostream>
using namespace std;

//  Создайте функцию, которая принимает 2 указателя (на начало и конец массива) и которая возвращает сумму всех элементов массива.
int summArray(int* nach, int* kon) {
    int summa = 0;
    for (int* pntr = nach; pntr < kon; pntr++) {
        summa += *pntr;
    }
    return summa;
}

// Создайте 2 функции, принимающих 2 параметра и возвращающих их сумму и их разность соответственно.
int sum(int a, int b) {
    return a + b;
}

int raz(int a, int b) {
    return a - b;
}

// Создайте функцию, принимающую 1 параметр типа char.
int (*sum_or_raz(char x))(int, int) {
    if (x == '-') return raz;
    else if (x == '+') return sum;
}

int main()
{
    setlocale(LC_ALL, "russian");
    //int array[] = { 1,2,3,4,5,6,7,8,9 }; 45
    //int array[] = { 55, 34, 78, 12 }; 179
    //cout << summArray(array, end(array))<< endl; 
    //cout << raz(1, 2) << " " << sum(1, 2) << endl;
    char a;
    cin >> a;
    cout << sum_or_raz(a) << endl;
    int (*result)(int, int) = sum_or_raz(a);
    cout << result(1, 3) << endl;
    float* n = new float(3.14);
    cout << *n;
}
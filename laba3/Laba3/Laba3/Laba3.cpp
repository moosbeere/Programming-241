
#include <iostream>
using namespace ::std;

int suma(int s, int f, int arr[])
{
    int summa = 0;
    for (s; s < f; s++)
    {
        summa += arr[s];
    }
    return summa;
}

int suma2(int a, int b)
{
    return a + b;
}

int razn(int a, int b)
{
    return a - b;
}

int (*operation(char choice))(int, int)
{
    if (choice == '+')
        return &suma2;
    else if (choice == '-')
        return &razn;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 3;
    int* pn = &n;
    cout << "Адрес: " << pn << " Значение: " << *pn << "\n";

    *pn = 4;
    cout << "Переменная при изменении указателя: " << *pn << "\n";

    const int a = 5;
    int arr[a] = {1, 7, 4, 6, 0};
    int* parr = arr;
    for (int i = 0; i < a; i++)
    {
        cout << *(parr + i) << " ";
    }
    cout << "\n";

    int h = 5;
    int* const ph = &h;
    *ph = 10;
    cout << h;

    cout << "\nЗадание 2\n";

    int arrr[5] = { 1, 3, 4, 5, 6};
    int s = 0;
    int f = 5;
    cout << suma(s, f, arrr) <<"\n";


    int (*op)(int, int);
    op = operation('-');
    cout << op(2, 6) << "\n`w";

    float* pfloat = new float;
    *pfloat = 1.3232;
    cout << *pfloat;
    delete pfloat;
}



#include "Header.h"
#include <iostream>
#include <string>

#define SUM(a, b) ((a) + (b))
using namespace ::std;

int f1(int n)
{
    if (n == 0 || n < 0) {
        return 0;
    }
    int suma = 0;
    for (int i = 0; i <= n; i++)
    {
        suma += i;
    }
    return suma;
}

int f2(int n = 1)
{
    if (n == 0 || n < 0) {
        return 0;
    }
    int suma = 0;
    for (int i = 0; i <= n; i++)
    {
        suma += i;
    }
    return suma;
}

void f3(int q, int w, int& e, int& r)
{
    e = q + w;
    r = q * w;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Задание 1\n";

    double a, b;
    cout << "Введите 2 числа: ";
    cin >> a >> b;
    double c = (a + b) / 2;
    cout << "Среднее арифметическое: " << c << "\n";

    cout << "Введите знак операции: + - *: ";
    char answ;
    while (true) {
        cin >> answ;
        switch (answ) {
            case '+':
                cout << a + b;
                break;
            case '*':
                cout << a * b;
                break;
            case '-':
                cout << a - b;
                break;
            default:
                cout << "Ошибка, повторите попытку: ";
                continue;
        }
        break;
    }
    cout << "\n Задание 2 \n";
    int p;
    while (true) {
        cout << "Введите целое положительное число: ";
        cin >> p;
        if (p < 0)
            cout << "Число отрицательное\n";
        else break;
    }
    int summa = 0;
    for (int i = 1; i <= p; i++) {
        summa += i;
    }
    cout <<"Сумма "<< summa << "\n";

    cout << "\n";
    int arr[10]
    {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10
    };
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n Числа на четных местах: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            cout << arr[i] << " ";
    }

    cout << "\n Числа на нечетных местах: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0)
            cout << arr[i] << " ";
    }

    cout << "\n Задание 3\n";
    int array[2][3] =
    {
        1, 2, 3,
        4, 5, 6
    };
    int suma = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            suma += array[i][j];
        }
    }
    cout << suma << "\n";
    int massiv[3] = { array[0][0] + array[1][0], array[0][1] + array[1][1], array[0][2] + array[1][2] };
    for (int i = 0; i < 3; i++)
    {
        cout << massiv[i] << " ";
    }
    cout << "\n";
    
    float per = 20.84;
    float* perp = &per;
    float* perpp = &per;
    *perpp = 3;
    cout << per << " " << *perp << " " << *perpp << "\n";

    int n;
    cout << "Введите число \n";
    cin >> n;
    cout << "C параметром " << f1(n) << "\n";
    cout << "Без параметра " << f2() << "\n";

    
   
    int q = 12;
    int w = 45;
    int e = 6;
    int r = 7;

    f3(q, w, e, r);
    cout << e << " " << r << "\n";

    int t;
    cout << "Переменная типа int: ";
    cin >> t;
    for (int i = 0; i < 3; i++)
    {
        int y = 4;
        cout << "Объявленная вне цикла переменная " << t << "\n";
        cout << "Объявленная внутри цикла переменная " << y << "\n";
    }   
    //cout << "Объявленная вне цикла переменная, вне цикла " << y; ОШИБКА
    cout << "\n Задание 4\n";

    int l = 4;
    zad4(l);
    l = 100;
    zad4(l);
    l = 300;
    zad4(l);
    cout << "Можем видеть,что статическая переменная изменяет свое значение и сохраняет его вне функции\n";
    
    int z = 3;
    int x = 5;
    cout << SUM(3, 5);

   
}

    
    




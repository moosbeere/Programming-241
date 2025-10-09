

#include <iostream>
#include <string>

using namespace ::std;

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



   

   
}

    
    




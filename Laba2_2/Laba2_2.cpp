//1.    Получите от пользователя 2 числа.
//2.    Выведите среднее арифметическое двух введённых чисел в консоль.
//3.    Попросите пользователя ввести знак операции : +, -, * или / .
//4.    Сохраните эту команду в переменную.
//5.    Используя условный оператор, выполните соответствующую операцию с двумя ранее введёнными числами.То есть, если, например, пользователь ввёл*, то надо вывести результат перемножения этих чисел.
//6.    Закомментируйте код из предыдущего пункта и реализуйте его с использованием оператора switch - case.

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    
    float a, b, result;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    int action;
    cout << "Введите знак операции ( 1 - +, 2 - - ,3 - * или 4 - / ) : ";
    cin >> action;

    /*if (action == 1)
        result = a + b;
    else if (action == 2)
        result = a - b;
    else if (action == 3)
        result = a * b;
    else if (action == 4)
        result = a / b;
    cout << result << endl;*/

    switch (action)
    {
    case (1): 
        {
        result = a + b;
        cout << result;
        break;
        }
    case (2):
    {
        result = a - b;
        cout << result;
        break;
    }
    case (3):
    {
        result = a * b;
        cout << result;
        break;
    }
        default:
        {
            result = a / b;
            cout << result;
            break;
        }
    }

    return 0;
}

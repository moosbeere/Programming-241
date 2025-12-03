////ЗАДАНИЕ  2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    //запрос целого положительного числа
    int number;
    while (true) {
        cout << "введите целое положительное число: ";
        cin >> number;

        if (number > 0) {
            break; // выходим из цикла, если число положительное
        }
        else {
            cout << "число должно быть положительным! попробуйте еще раз." << endl;
        }
    }

    //сумма всех чисел от 1 до введённого
    int sum = 0;
    cout << "сумма чисел от 1 до " << number << ": ";
    for (int i = 1; i <= number; i++) {
        sum += i;
        cout << i;
        if (i < number) {
            cout << " + ";
        }
    }
    cout << " = " << sum << endl << endl;

    //создаём массив из 10 чисел
    int numbers[10] = { 5, 12, 8, 3, 17, 9, 14, 6, 11, 2 };

    //выводим все числа массива
    cout << "все числа массива: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i];
        if (i < 9) {
            cout << " "; // пробел между числами
        }
    }
    cout << endl << endl;

    //числа на чётных позициях (0, 2, 4, 6, 8)
    cout << "числа на чётных позициях: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) { // если остаток от деления на 2 равен 0
            cout << numbers[i] << " ";
        }
    }
    cout << endl;

    //сумма элементов на нечётных позициях (1, 3, 5, 7, 9)
    int sumnechet = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) { // если остаток от деления на 2 НЕ равен 0
            sumnechet += numbers[i];
        }
    }
    cout << "сумма чисел на нечётных позициях: " << sumnechet << endl;

    return 0;
}

////ЗАДАНИЕ 3
#include <iostream>
using namespace std;
int f1(int n) {
    if (n <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int f2(int n = 1) {
    return f1(n);
}

void f3(int a, int b, int& sum, int& product) {
    sum = a + b;
    product = a * b;
}

int main() {
    //двумерный массив и сумма
    int array[2][3] = {
        1, 2, 3,
        4, 5, 6
    };

    int suma = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            suma += array[i][j];
        }
    }
    cout << "сумма всех чисел: " << suma << "\n";

    //одномерный массив сумм столбцов
    int massiv[3] = {
        array[0][0] + array[1][0],
        array[0][1] + array[1][1],
        array[0][2] + array[1][2]
    };

    cout << "суммы столбцов: ";
    for (int i = 0; i < 3; i++) {
        cout << massiv[i] << " ";
    }
    cout << "\n";

    //переменная и ссылки
    float per = 20.84;
    float& ref1 = per; 
    float& ref2 = per;  

    cout << "до изменения: " << per << "\n";
    ref2 = 3.0f;  //меняем через ссылку

    cout << "после изменения: ";
    cout << per << " " << ref1 << " " << ref2 << "\n";

    //функция с параметром по умолчанию
    int n;

    //бесконечный цикл для проверки положительности
    while (true) {
        cout << "введите положительное число: \n";
        cin >> n;
        if (n > 0) {
            break;
        }
        cout << "число должно быть положительным!\n";
    }

    cout << "с параметром: " << f1(n) << "\n";
    cout << "без параметра: " << f2() << "\n";

    //функция с параметрами по ссылке
    int q = 12;
    int w = 45;
    int e = 6;
    int r = 7;

    cout << "до вызова f3: e = " << e << ", r = " << r << "\n";
    f3(q, w, e, r);
    cout << "после вызова f3: e = " << e << ", r = " << r << "\n";

    //циклы и переменные
    int t;
    cout << "введите число: ";
    cin >> t;

    for (int i = 0; i < 3; i++) {
        int y = 4 + i;  //разные значения в каждой итерации
        cout << "итерация " << i + 1 << ":\n";
        cout << "переменная t (объявлена вне цикла): " << t << "\n";
        cout << "переменная y (объявлена в цикле): " << y << "\n";
    }

    //попытка обратиться к переменной из цикла
    // cout << "y = " << y << "\n";  //ошибка

    return 0;
}


//ЗАДАНИЕ 4
#include <iostream>
#include "MyMath.h"


#define sum(a, b) ((a) + (b))

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    MyMath::calc(5);
    MyMath::calc(10);
    MyMath::calc(3);


    cout << "работа макроса: " << sum(7, 3) << endl;
    cout << "работа макроса: " << sum(15, 25) << endl;

    return 0;
}

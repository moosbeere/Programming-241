#include <iostream>

using namespace std;


// функция для суммы массива
int func(int* start, int* end) {
    int s = 0;
    for (*start; start <= end; start++) {
        s += *start;
    }
    return s;
}

// функция для суммы двух чисел
int diff(int* one, int* two) {
    return *one - *two;
}

// функция для разности двух чисел
int summ(int* one, int* two) {
    return *one + *two;
}

// Адаптеры для функций summ и diff, которые будут принимать int
int summ_adapter(int a, int b) {
    return summ(&a, &b);
}

int diff_adapter(int a, int b) {
    return diff(&a, &b);
}

// функция, возвращающая указатель на функцию с нужной сигнатурой
int (*operFunc(char op))(int, int) {
    if (op == '+') {
        return &summ_adapter;
    }
    else if (op == '-') {
        return &diff_adapter;
    }
    return nullptr;
}


int main()
{
    setlocale(LC_ALL, "Ru");
    int arr[] = { 1, 2, 3, 4 };
    int* first = &arr[0];
    int* last = &arr[3];
    cout << "Сумма массива {1, 2, 3, 4} = " << func(first, last) << endl;

    int a = 10;
    int b = 20;
    int* uno = &a;
    int* dos = &b;
    cout << "Сумма a = 10 и b = 20: " << summ(uno, dos) << endl;
    cout << "Разность a = 10 и b = 20: " << diff(uno, dos) << endl;

    int (*select_minus)(int, int) = operFunc('-');
    int (*select_plus)(int, int) = operFunc('+');
    cout << "Разность a и b при помощи функции указателя: " << select_minus(a, b) << endl;
    cout << "Сумма a и b при помощи функции указателя: " << select_plus(a, b) << endl;

    float pi = 3.14;
    float* dynamicFloat = new float;
    cout << "Динамический float: " << *dynamicFloat << endl << "Адрес: " << dynamicFloat;
    delete dynamicFloat;
    // cout << dynamicFloat;
    /* если раскоментировать строку выше, то программа будет запускаться,
     но при выполнении этой строки выдаст ошибку */
}
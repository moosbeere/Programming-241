#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int x = 10;

    int* y = &x;

    cout << "Адрес указателя: " << y << endl;
    cout << "Значение по адресу: " << *y << endl;

    *y = 99;

    cout << "\nНовое значение переменной value: " << x << endl;

    int arr[5] = { 1, 2, 3, 4, 5 };

    cout << "\nЭлементы массива через указатель: ";
    int* p = arr;
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    int number = 5;

    int* const yConst = &number;

    // yConst = &x; ошибка
    *yConst = 777;

    cout << "\nНовое значение number: " << number << endl;

    return 0;
}

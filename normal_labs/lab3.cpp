#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a = 10;
    
    // объявляем указатель "p" на переменную "a"
    int* p = &a;

    cout << "Адрес переменной a: " << p << endl;
    cout << "Значение по адресу p: " << *p << endl;
    
    // меняем значение по адресу "p"
    *p = 25;

    cout << "Новое значение переменной a: " << a << endl;


    int arr[5] = {3, 6, 9, 12, 15};

    int* parr = arr;
    cout << "\nЭлементы массива: ";
    for (int i = 0; i < 5; i++) {
        cout << *(parr + i) << " ";
    }
    cout << endl;

    int b = 5;

    // указатель, который нельзя переназначить
    int* const pConst = &b;

    // pConst = &a; // <-- Ошибка
    *pConst = 20;

    cout << "Новое значение переменной b: " << b << endl;

    return 0;
}

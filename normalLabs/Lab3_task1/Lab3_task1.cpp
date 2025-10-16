#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int a = 25;
    int* pointer = &a;
    cout << "pointer = " << *pointer << endl << "Ячейка памяти: " << pointer << endl;
    *pointer = 35;
    cout << "pointer = " << *pointer << endl << "Значение первоначальной переменной a =  " << a << endl;
    
    int arr[] = { 1, 2, 3 };
    cout << "Вывод массива с помощью указателя: ";
    for (int* i = arr; i <= &arr[2]; i++) { cout << *i << " "; }

    int b = 5;
    int* const ptr = &b;
    cout << endl << "b = " << b << endl << "Указатель с постоянным адресом ptr = " << *ptr << endl;
    cout << "Адрес показателя: " << ptr << endl;
    *ptr = 10;
    cout << "Значение после изменения указателя ptr = " << *ptr << endl << "Адрес: " << ptr << endl;
    int c = 123;
    // ptr = *c;
    // чтобы получить ошибку надо раскоментировать строку выше, ошибка возникает, потому что нельзя поменять адрес константы
    return 0;
}

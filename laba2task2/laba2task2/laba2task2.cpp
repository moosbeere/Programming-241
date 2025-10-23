#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int number;
    while (true) {
        cout << "Введите целое положительное число: ";
        cin >> number;

        if (number > 0) {
            break;  // Выход из цикла при правильном вводе
        }
        else {
            cout << "Ошибка: число должно быть положительным! Попробуйте снова." << endl;
        }
    }
    int sum = 0;
    cout << "Сумма чисел от 1 до " << number << ": ";
    for (int i = 1; i <= number; i++) {
        sum += i;
        cout << i;
        if (i < number) {
            cout << " + ";
        }
    }
    cout << " = " << sum << endl;
    
    int array[10] = { 2, 5, 8, 12, 15, 18, 22, 25, 30, 35 };
    
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i];
        if (i < 9) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "Числа на чётных позициях: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {  // Проверка на чётность позиции
            cout << array[i] << " ";
        }
    }
    cout << endl;

    int oddPositionsSum = 0;
    cout << "Сумма элементов на нечётных позициях: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {  // Проверка на нечётность позиции
            oddPositionsSum += array[i];
            cout << array[i];
            if (i < 9) {
                cout << " + ";
            }
        }
    }
    cout << " = " << oddPositionsSum << endl;

    return 0;
}


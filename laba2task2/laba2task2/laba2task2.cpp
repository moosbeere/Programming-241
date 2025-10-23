#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1. Запрос целого положительного числа с проверкой
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

    // 2. Вычисление суммы всех чисел от 1 до введённого числа
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

    // 3. Создание массива из 10 чисел
    int array[10] = { 2, 5, 8, 12, 15, 18, 22, 25, 30, 35 };

    // 4. Вывод всех 10 чисел из массива
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i];
        if (i < 9) {
            cout << " ";
        }
    }
    cout << endl;

    // 5. Вывод чисел на чётных позициях (0, 2, 4, 6, 8)
    cout << "Числа на чётных позициях: ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {  // Проверка на чётность позиции
            cout << array[i] << " ";
        }
    }
    cout << endl;

    // 6. Вывод суммы элементов на нечётных позициях (1, 3, 5, 7, 9)
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

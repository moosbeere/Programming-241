#include <iostream>
using namespace std;

int main() {
    int n;
    while (true) {
        cout << "Введите целое положительное число: ";
        cin >> n;
        if (n > 0) {
            break;
        }
        cout << "Ошибка: введите положительное число!" << endl;
    }

    int sum = 0;
    cout << "Сумма чисел от 1 до " << n << ": ";
    for (int i = 1; i <= n; ++i) {
        sum += i;
        cout << i;
        if (i != n) cout << " + ";
    }
    cout << " = " << sum << endl;

    int arr[10] = {3, 7, 2, 9, 14, 5, 10, 21, 8, 1};

    cout << "Все элементы массива: ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i];
        if (i != 9) cout << " ";
    }
    cout << endl;

    cout << "Числа на чётных позициях: ";
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    int sum_odd_pos = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 != 0) {
            sum_odd_pos += arr[i];
        }
    }
    cout << "Сумма элементов на нечётных позициях: " << sum_odd_pos << endl;

    return 0;
}



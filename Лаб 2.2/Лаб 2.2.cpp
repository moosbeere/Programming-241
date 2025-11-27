#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    while (true) {
        cout << "Введите положительное число: ";
        cin >> n;
        if (n > 0) break;
        cout << "Ошибка! Введите положительное число!\n";
    }

    int sum = 0;
    cout << "1";
    sum = 1;

    for (int i = 2; i <= n; i++) {
        cout << " + " << i;
        sum += i;
    }
    cout << " = " << sum << endl;

    int arr[10] = { 3, 7, 1, 9, 4, 6, 2, 8, 5, 10 };

    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Чётные позиции: ";
    for (int i = 0; i < 10; i++)
        if (i % 2 == 0) cout << arr[i] << " ";
    cout << endl;

    int oddSum = 0;
    for (int i = 0; i < 10; i++)
        if (i % 2 == 1) oddSum += arr[i];
    cout << "Сумма нечётных позиций: " << oddSum << endl;

    return 0;
}

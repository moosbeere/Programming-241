#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    setlocale(LC_ALL, "ru");

    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    if (N < 0) {
        cout << "Ошибка: число должно быть натуральным" << endl;
        return 1;
    }

    int sum = sumOfDigits(N);
    cout << "Сумма цифр числа " << N << " равна: " << sum << endl;

    return 0;
}
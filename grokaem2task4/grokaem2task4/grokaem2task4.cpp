#include <iostream>
using namespace std;

void findPrimeDivisors(int n, int divisor) {
    if (n == 1) {
        return;
    }

    if (divisor * divisor > n) {
        cout << n << " ";
        return;
    }

    if (n % divisor == 0) {
        cout << divisor << " ";
        while (n % divisor == 0) {
            n /= divisor;
        }
    }

    findPrimeDivisors(n, divisor + 1);
}

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите натуральное число n > 1: ";
    cin >> n;

    if (n <= 1) {
        cout << "Ошибка: число должно быть больше 1" << endl;
        return 1;
    }

    cout << "Простые делители числа " << n << ": ";
    findPrimeDivisors(n, 2);
    cout << endl;

    return 0;
}
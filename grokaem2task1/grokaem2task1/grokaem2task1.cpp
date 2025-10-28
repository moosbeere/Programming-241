#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n - 1);
        cout << n << " ";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: число должно быть натуральным (больше 0)" << endl;
        return 1;
    }

    cout << "Числа от 1 до " << n << ": ";
    printNumbers(n);
    cout << endl;

    return 0;
}
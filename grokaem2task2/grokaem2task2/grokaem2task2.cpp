#include <iostream>
using namespace std;

void printAscending(int a, int b) {
    if (a <= b) {
        cout << a << " ";
        printAscending(a + 1, b);
    }
}

void printDescending(int a, int b) {
    if (a >= b) {
        cout << a << " ";
        printDescending(a - 1, b);
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int A, B;
    cout << "Введите число A: ";
    cin >> A;
    cout << "Введите число B: ";
    cin >> B;

    cout << "Числа от " << A << " до " << B << ": ";

    if (A < B) {
        printAscending(A, B);
    }
    else {
        printDescending(A, B);
    }

    cout << endl;
    return 0;
}
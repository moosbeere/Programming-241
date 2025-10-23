#include <iostream>
using namespace std;

void f(int n, int x = 2) {
    if (n == 1) return;

    if (n % x == 0) {
        cout << x << " ";
        f(n / x, x);
    }
    else {
        f(n, x + 1);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите число: ";
    int n;
    cin >> n;
    f(n);
    return 0;
}
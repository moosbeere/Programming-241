#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0) return 0;
    return n % 10 + f(n / 10);
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите число: ";
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}
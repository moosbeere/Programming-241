#include <iostream>
using namespace std;

void f(int x) {
    if (x > 0) {
        f(x - 1);
        cout << x;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int x;
    cout << "Введите число: ";
    cin >> x;
    f(x);
    return 0;
}
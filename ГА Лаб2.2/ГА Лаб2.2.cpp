#include <iostream>
using namespace std;

void f(int x, int y) {
    cout << x;

    if (x == y) return;
    
    if (x < y) {
        f(x + 1, y);
    }
    
    if (y < x) {
        f(x - 1, y);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите число A: ";
    int x;
    cin >> x;
    cout << "Введите число B: ";
    int y;
    cin >> y;
    f(x, y);
    return 0;
}
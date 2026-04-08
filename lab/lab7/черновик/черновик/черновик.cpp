#include <iostream>
using namespace std;

// Рекурсивная функция для вывода чисел от A до B
void printRange(int a, int b) {
    // Базовый случай: если A > B или A < B в зависимости от направления
    if ((a <= b && a > b) || (a >= b && a < b)) {
        return;
    }

    // Выводим текущее число
    cout << a << " ";

    // Рекурсивный вызов с шагом +1 или -1
    if (a < b) {
        printRange(a + 1, b);  // возрастающий порядок
    }
    else {
        printRange(a - 1, b);  // убывающий порядок
    }
}

int main() {
    int a, b;

    cout << "Введите число A: ";
    cin >> a;
    cout << "Введите число B: ";
    cin >> b;

    cout << "Числа от " << a << " до " << b << ": ";
    printRange(a, b);
    cout << endl;

    return 0;
}
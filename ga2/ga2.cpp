#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

// 1. Числа от 1 до n
void print_1_to_n(int n) {
    if (n == 0)
        return;
    print_1_to_n(n - 1);
    cout << n << " ";
}

// 2. Числа от A до B
void print_a_to_b(int a, int b) {
    cout << a << " ";
    if (a == b)
        return;
    if (a < b)
        print_a_to_b(a + 1, b);
    else
        print_a_to_b(a - 1, b);
}

// 3. Сумма цифр числа
int sum_of_digits(int n) {
    if (n < 10)
        return n;
    return n % 10 + sum_of_digits(n / 10);
}

// 4. Простые делители числа
void print_prime_divisors(int n, int d = 2) {
    if (d > n)
        return;
    if (n % d == 0)
        cout << d << " ";
    print_prime_divisors(n, d + 1);
}

int main() {
    // Русский язык в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int n, A, B;

    // Задание 1
    cout << "Задание 1\nВведите натуральное число n: ";
    cin >> n;
    cout << "Числа от 1 до n: ";
    print_1_to_n(n);
    cout << "\n\n";

    // Задание 2
    cout << "Задание 2\nВведите A: ";
    cin >> A;
    cout << "Введите B: ";
    cin >> B;
    cout << "Числа от A до B: ";
    print_a_to_b(A, B);
    cout << "\n\n";

    // Задание 3
    cout << "Задание 3\nВведите число N: ";
    cin >> n;
    cout << "Сумма цифр: " << sum_of_digits(n) << "\n\n";

    // Задание 4
    cout << "Задание 4\nВведите число n (>1): ";
    cin >> n;
    cout << "Простые делители: ";
    print_prime_divisors(n);

    return 0;
}

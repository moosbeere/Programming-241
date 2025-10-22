#include <iostream>
#include <vector>

using namespace std;

// Простая рекурсивная функция для чисел от 1 до n
void printNumbers(int n) {
    if (n <= 0) return;
    printNumbers(n - 1);
    cout << n << " ";
}

// Рекурсивная функция для чисел от A до B
void printRange(int a, int b) {
    if (a == b) {
        cout << a << " ";
        return;
    }
    if (a < b) {
        cout << a << " ";
        printRange(a + 1, b);
    } else {
        cout << a << " ";
        printRange(a - 1, b);
    }
}

// Сумма цифр числа
int sumDigits(int n) {
    if (n < 10) return n;
    return (n % 10) + sumDigits(n / 10);
}

// Проверка на простоту
bool isPrime(int n, int i = 2) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % i == 0) return false;
    if (i * i > n) return true;
    return isPrime(n, i + 1);
}

int main() {
    cout << "Рекурсивные задачи" << endl;
    
    // Задача 1: Числа от 1 до 5
    cout << "Числа от 1 до 5: ";
    printNumbers(5);
    cout << endl;
    
    // Задача 2: Числа от 3 до 7
    cout << "Числа от 3 до 7: ";
    printRange(3, 7);
    cout << endl;
    cout << "Числа от 7 до 3: ";
    printRange(7, 3);
    cout << endl;
    
    // Задача 3: Сумма цифр
    int num = 12345;
    cout << "Сумма цифр числа " << num << " = " << sumDigits(num) << endl;
    
    // Задача 4: Простые числа
    cout << "Простые числа до 20: ";
    for (int i = 2; i <= 20; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
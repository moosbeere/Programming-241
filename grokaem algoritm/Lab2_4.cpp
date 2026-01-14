#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Рекурсивная функция для нахождения простых делителей
void findPrimeFactors(int n, int divisor, vector<int>& factors) {
    // Базовый случай: если число меньше или равно 1, завершаем рекурсию
    if (n <= 1) {
        return;
    }

    // Максимальный делитель для проверки - квадратный корень из n
    int maxDivisor = sqrt(n);

    // Если текущий делитель больше максимального, значит n - простое число
    if (divisor > maxDivisor) {
        factors.push_back(n);
        return;
    }

    // Проверяем, является ли текущий делитель простым
    if (n % divisor == 0) {
        // Добавляем простой делитель
        factors.push_back(divisor);

        // Рекурсивно вызываем функцию с уменьшенным n
        findPrimeFactors(n / divisor, divisor, factors);
    }
    else {
        // Если текущий делитель не подходит, увеличиваем его
        findPrimeFactors(n, divisor + 1, factors);
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите натуральное число n > 1: ";
    cin >> n;

    // Вектор для хранения простых делителей
    vector<int> primeFactors;

    // Начинаем с первого простого числа 2
    findPrimeFactors(n, 2, primeFactors);

    // Выводим простые делители
    cout << "Простые делители числа " << n << ": ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void printNumbersRec(int n) {
    if (n <= 0) return;
    printNumbersRec(n - 1);
    cout << n << " ";
}

// Рекурсивная функция для вывода чисел от A до B
void print(int a, int b) {
    if (a > b) {
        if (a <= b) return;
        cout << a << " ";
        print(a - 1, b);
    }
    else {
        if (a >= b) return;
        cout << a << " ";
        print(a + 1, b);
    }
}

int summator(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + summator(n / 10);
}

int vspomog(int n, int delit) {
    if (n % delit != 0) {
        return n;
    }
    vspomog(n / delit, delit);
}

void deliteli(int n, int delit) {
    if (n == 1) {
        return;
    }

    // Базовый случай 2: текущий делитель превысил корень из n
    if (delit > sqrt(n)) {
        // Оставшееся число n должно быть простым (если оно больше 1)
        if (n > 1) {
            cout << n << " ";
        }
        return;
    }


    // Проверяем, делит ли divisor число n
    if (n % delit == 0) {
        // divisor делит n, проверяем, является ли divisor простым
        // (он будет простым, т.к. мы проверяем делители по возрастанию
        // и уже убрали все меньшие простые делители)
        cout << delit << " ";

        // Убираем все вхождения этого делителя
        // это если поп расстому ноооо тк нам запрещено:(((( использовать все циклы
        // мы пойдем по более сложному пути, а именно рекурсивному)
        //while (n % delit == 0) {
        //    n /= delit;
        //}
        n = vspomog(n, delit);
    }

    // Рекурсивно проверяем следующий делитель
    deliteli(n, delit + 1);
}


int main() {
    setlocale(LC_ALL, "russian");
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;
    cout << "Числа от 1 до " << n << ": ";
    printNumbersRec(n);
    cout << endl;


    int a, b;
    cout << "Введите число A: ";
    cin >> a;
    cout << "Введите число B: ";
    cin >> b;
    cout << "Числа от " << a << " до " << b << ": ";
    if (a > b) {
        print(a, b);
        cout << b;
    }
    else {
        print(a, b);
        cout << b;
    }
    cout << endl;


    int num;
    cout << "Введите натуральное число N: ";
    cin >> num;
    if (num < 10) {
        cout << "Ошибка! Число должно быть натуральным (положительным) и больше 10" << endl;
    }
    cout << "Сумма цифр числа " << num << " = " << summator(num) << endl;


    int number;
    cout << "Введите натуральное число n (>1): ";
    cin >> number;
    if (number <= 1) {
        cout << "Число должно быть больше 1!" << endl;
    }
    cout << "Простые делители числа " << number << " (в порядке возрастания): ";
    deliteli(number, 2);
    cout << endl;
}


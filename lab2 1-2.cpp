#include <iostream>

using namespace std;

// Функция для вычисления суммы чисел от 1 до n
void calculateSum() {
    int n;
    cout << "Введите целое положительное число: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ошибка: число должно быть положительным!" << endl;
        return;
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    
    cout << "Сумма всех чисел от 1 до " << n << " = " << sum << endl;
}

// Функция для работы с массивом из 10 чисел
void workWithArray() {
    int numbers[10];
    
    // Заполняем массив числами от 2
    for (int i = 0; i < 10; i++) {
        numbers[i] = i + 2;
    }
    
    // Выводим числа в нужном формате
    cout << "Массив из 10 чисел: ";
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "первое число " << numbers[i];
        } else if (i == 1) {
            cout << ", второе число " << numbers[i];
        } else if (i == 2) {
            cout << ", третье число " << numbers[i];
        } else if (i == 3) {
            cout << ", четвертое число " << numbers[i];
        } else if (i == 4) {
            cout << ", пятое число " << numbers[i];
        } else if (i == 5) {
            cout << ", шестое число " << numbers[i];
        } else if (i == 6) {
            cout << ", седьмое число " << numbers[i];
        } else if (i == 7) {
            cout << ", восьмое число " << numbers[i];
        } else if (i == 8) {
            cout << ", девятое число " << numbers[i];
        } else if (i == 9) {
            cout << ", десятое число " << numbers[i];
        }
    }
    cout << endl;

    // Выводим числа на чётных позициях 
    cout << "Числа на чётных позициях (с 0): ";
    for (int i = 0; i < 10; i += 2) { // идём по чётным индексам сразу

            cout << ", ";

        cout << numbers[i];
    }
    cout << endl;
    // Выводим числа на нечётных позициях 
    cout << "Числа на нечётных позициях (с 0): ";
    for (int i = 1; i < 10; i += 2) { // идём по чётным индексам сразу

            cout << ", ";

        cout << numbers[i];
    }
    cout << endl;
}

int main() {
    double a, b;

    cout << "Введите два числа: ";
    cin >> a >> b;

    char op;
    cout << "Введите знак операции (+ - * /): ";
    cin >> op;


    double result;
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                cout << "Ошибка: деление на ноль" << endl;
                return 0;
            }
            result = a / b;
            break;
        default:
            cout << "Неизвестная операция" << endl;
            return 0;
    }

    cout << "Результат операции: " << result << endl;

    double average = (a + b) / 2;

    cout << "Среднее арифметическое: " << average << endl;

    // Вызываем функцию для вычисления суммы
    calculateSum();

    // Вызываем функцию для работы с массивом
    workWithArray();

    return 0;
}



#include <iostream>
#include <locale>

using namespace std;

// Функция включения поддержки русского языка
void enableRussian() {
    setlocale(LC_ALL, "");
}

// 1. Функция суммы элементов массива через указатели
int sumArray(int* begin, int* end) {
    int sum = 0;
    for (int* p = begin; p != end; ++p) {
        sum += *p;
    }
    return sum;
}

// 3. Функция суммы двух чисел
int sum(int a, int b) {
    return a + b;
}

// 3. Функция разности двух чисел
int diff(int a, int b) {
    return a - b;
}

// 4–5. Функция, возвращающая указатель на функцию
int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return sum;
    }
    else if (op == '-') {
        return diff;
    }
    return nullptr; // если символ некорректный
}

int main() {
    enableRussian(); // ✅ поддержка русского языка

    // 2. Проверка функции суммы массива
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int arraySum = sumArray(arr, arr + size);
    cout << "Сумма элементов массива: " << arraySum << endl;

    cout << "-----------------------------" << endl;

    // 6. Проверка работы указателей на функции
    char operation = '+';
    int (*funcPtr)(int, int) = getOperation(operation);

    if (funcPtr != nullptr) {
        int result = funcPtr(10, 3);
        cout << "Результат операции '" << operation << "': " << result << endl;
    }

    operation = '-';
    funcPtr = getOperation(operation);

    if (funcPtr != nullptr) {
        int result = funcPtr(10, 3);
        cout << "Результат операции '" << operation << "': " << result << endl;
    }

    cout << "-----------------------------" << endl;

    // 7. Динамический указатель типа float
    float* floatPtr = new float(20.84f);

    // 8. Вывод значения и освобождение памяти
    cout << "Значение динамической переменной float: " << *floatPtr << endl;

    delete floatPtr;   // освобождение памяти
    floatPtr = nullptr; // защита от висячего указателя

    return 0;
}

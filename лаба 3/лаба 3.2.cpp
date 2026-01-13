#include <iostream>
#include <locale>
#include <clocale>

// 1. Функция суммы элементов массива через указатели
int sumArray(const int* begin, const int* end) {
    int sum = 0;
    for (const int* ptr = begin; ptr != end; ++ptr) {
        sum += *ptr;
    }
    return sum;
}

// 3. Функции суммы и разности
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 4,5. Функция, возвращающая указатель на функцию в зависимости от char
int (*operation(char op))(int, int) {
    if (op == '+') {
        return add;
    } else if (op == '-') {
        return subtract;
    }
    return nullptr; // в случае некорректного символа
}

// Альтернативный вариант с использованием typedef для читаемости
typedef int (*MathFunc)(int, int);

MathFunc operation2(char op) {
    if (op == '+') return add;
    if (op == '-') return subtract;
    return nullptr;
}

int main() {
    // Настройка локали для поддержки русского языка
    #ifdef _WIN32
        // Для Windows
        setlocale(LC_ALL, "Russian");
        system("chcp 1251 > nul"); // Установка кодовой страницы 1251 (Windows-1251)
    #else
        // Для Linux/macOS
        setlocale(LC_ALL, "ru_RU.UTF-8");
    #endif
    
    // 2. Проверка функции суммы массива
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = sumArray(arr, arr + size);
    std::cout << "Сумма элементов массива: " << sum << std::endl;
    
    // 6. Проверка работы с указателями на функции
    char op = '+';
    int (*funcPtr)(int, int) = operation(op);
    
    if (funcPtr) {
        int result = funcPtr(10, 5);
        std::cout << "10 " << op << " 5 = " << result << std::endl;
    }
    
    op = '-';
    funcPtr = operation(op);
    if (funcPtr) {
        int result = funcPtr(10, 5);
        std::cout << "10 " << op << " 5 = " << result << std::endl;
    }
    
    // 7,8. Динамический указатель типа float
    float* floatPtr = new float(3.14159f);
    std::cout << "Динамический указатель: " << *floatPtr << std::endl;
    
    // 8. Удаление из памяти
    delete floatPtr;
    floatPtr = nullptr;
    
    return 0;
}
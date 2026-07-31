#include <iostream>

// 1. Функция для вычисления суммы элементов массива через указатели
int sumArray(const int* begin, const int* end) {
    int sum = 0;
    for (const int* ptr = begin; ptr != end; ++ptr) {
        sum += *ptr;
    }
    return sum;
}

// 3. Функции для суммы и разности
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 4-5. Функция, возвращающая указатель на функцию суммы или разности по символу
typedef int (*OpFunc)(int, int);

OpFunc chooseOp(char op) {
    if (op == '+') return &add;
    if (op == '-') return &subtract;
    return nullptr; // в случае некорректного символа
}

int main() {
    // 2. Проверка функции суммы массива
    int arr[] = {1, 2, 3, 4, 5};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int sumptr = sumArray(arr, arr + sz);
    std::cout << "Сумма элементов массива: " << sumptr << std::endl;

    // 6. Проверка выбора функции и вызова по указателю
    char op = '+'; // попробуйте и '-'
    OpFunc funcPtr = chooseOp(op);
    if (funcPtr) {
        int result = funcPtr(10, 4);
        std::cout << "Результат функции для '" << op << "': " << result << std::endl;
    } else {
        std::cout << "Некорректный оператор!" << std::endl;
    }

    // 7. Динамический указатель типа float, вывод и удаление
    float* pFloat = new float(3.14f);
    std::cout << "Значение динамического float: " << *pFloat << std::endl;
    delete pFloat;

    return 0;
}

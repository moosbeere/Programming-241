#include <iostream>

// Сумма элементов по двум указателям [begin, end)
int sum_range(const int* begin, const int* end) {
    int s = 0;
    for (const int* p = begin; p != end; ++p) {
        s += *p;
    }
    return s;
}

//  Две функции: сумма и разность
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

// Тип указателя на функцию "int (int,int)"
using binop = int(*)(int, int);

// Функция, принимающая char,
// возвращающая указатель на add/sub в зависимости от символа
binop choose_op(char c) {
    if (c == '+') return &add;
    if (c == '-') return &sub;
    return nullptr; // на невалидный символ
}

int main() {
    int arr[] = { 2, 5, -3, 10, 4 };
    int total = sum_range(std::begin(arr), std::end(arr));
    std::cout << "Sum of arr = " << total << "\n"; // должно быть 18

    // 6) Проверка выбора функции по символу и вызов по указателю
    char op_char = '+';             // попробуйте '-' для разности
    binop op = choose_op(op_char);  // сначала получаем указатель на функцию
    if (op) {
        int a = 7, b = 3;
        int result = op(a, b);      // затем вызываем через указатель
        std::cout << a << " " << op_char << " " << b << " = " << result << "\n";
    } else {
        std::cout << "Unknown operation: '" << op_char << "'\n";
    }

    // 7) Создать динамический указатель типа float
    float* pf = new float(10.0f);

    // 8) Вывести и освободить память
    std::cout << "Dynamic float value = " << *pf << "\n";
    delete pf;
    pf = nullptr; // на всякий случай

    return 0;
}

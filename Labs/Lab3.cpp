#include <iostream>
#include <clocale>


// Задание 1

static void runTask1()
{
    // Обычная переменная и указатель на неё
    int value = 12;
    int* ptrValue = &value;

    std::cout << ptrValue << " -> " << value << std::endl;

    // Изменяем значение через указатель
    *ptrValue = 55;
    std::cout << ptrValue << " -> " << value << std::endl;

    // Массив и указатель на первый элемент
    constexpr int ARRAY_SIZE = 4;
    int numbers[ARRAY_SIZE] = { 14, 543, 12, 435 };
    int* ptrArray = numbers;

    std::cout << "Вывод массива:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout
            << std::addressof(numbers[i])
            << " -> "
            << numbers[i]
            << std::endl;
    }

    // Константный указатель (адрес менять нельзя)
    int b = 5;
    int* const constPtrB = &b;

    std::cout << "Старое значение b: " << b << std::endl;

    // constPtrB = &value; // ошибка
    *constPtrB = 234;

    std::cout << "Новое значение b: " << b << std::endl;
}


// Задание 2


// Сумма элементов массива по указателям начала и конца
static int sumArray(int* begin, int* end)
{
    int result = 0;

    while (begin != end)
    {
        result += *begin;
        ++begin;
    }

    // Добавляем последний элемент
    result += *end;
    return result;
}

// Арифметические операции
static int add(const int a, const int b)
{
    return a + b;
}

static int subtract(const int a, const int b)
{
    return a - b;
}

// Тип указателя на функцию
using MathFunction = int(*)(const int, const int);

// Возвращает нужную функцию по символу
static MathFunction chooseOperation(const char operation)
{
    if (operation == '+')
        return add;
    else if (operation == '-')
        return subtract;

    return nullptr;
}

static void runTask2()
{
    constexpr int ARRAY_SIZE = 3;
    int values[ARRAY_SIZE] = { 1, 2, 3 };

    std::cout
        << "Сумма массива: "
        << sumArray(values, values + ARRAY_SIZE - 1)
        << std::endl;

    // Получаем функцию по символу
    MathFunction operation = chooseOperation('+');

    if (operation != nullptr)
    {
        std::cout
            << "Результат функции: " << operation(1, 5) << std::endl;
    }

    // Динамический массив
    float* dynamicArray = new float[5];

    std::cout << "Динамический массив:" << std::endl;
    for (int i = 0; i < 5; ++i)
        std::cout << dynamicArray[i] << std::endl;

    delete[] dynamicArray;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    runTask2();
}

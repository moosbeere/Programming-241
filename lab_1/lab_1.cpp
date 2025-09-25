// Подключение библиотеки iostream
#include <iostream>

static void task_1()
{
    // Исправление кодировки
    std::setlocale(LC_ALL, "Russian");

    // Вывод строки First string
    std::cout << "First string" << std::endl;
    // Вывод строки Первая строка\nВторая строка
    std::cout << "Первая строка\nВторая строка" << std::endl;
    // Вывод строки Спецсимволы \"\\\"
    std::cout << "Спецсимволы \"\\\"" << std::endl;
}

static void task_2()
{
    int a = 150;
    float b = 15.933f;
    uint8_t c = 250;

    std::cout << "a = 150" << std::endl;
    std::cout << "b = 15.933" << std::endl;
    std::cout << "c = 250" << std::endl;

    uint8_t day = 27;
    const char* month = "Сентябрь";
    int year = 2006;

    std::printf("Моя дата рождения: %d %s %d года\n", day, month, year);

    const uint8_t i = 2;
    const uint8_t j = 3;
    const char* windows = "WINDOWS";
    std::printf("%d %d %s\n", i, j, windows);
}

int main()
{
    std::setlocale(LC_ALL, "Russian");

    int task = 0;
    std::cout << "Введите номер задания" << std::endl;
    std::cin >> task;

    if (task == 1)
        task_1();
    else
        task_2();
} // Завершающая фигурная скобка main

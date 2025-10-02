#include <iostream>
#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*int x;
    while (true) {
        std::cout << "Введите целое положительное число: ";
        std::cin >> x;
        if (x > 0) {
            break; // правильный ввод, выходим из цикла
        }
        else {
            std::cout << "Ошибка: число должно быть положительным. Попробуйте снова." << std::endl;
        }
    }
    int sum = 0;
    for (int i = 1; i <= x; ++i) {
        sum += i;
    }
    std::cout << "Сумма чисел от 1 до " << x << " равна: " << sum << std::endl;
    return 0;*/
    int arr[10] = { 1,4,78,4,9,67,17,15,8,6 }; //создали массив
    std::cout << "Все числа массива: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i];
        if (i < 9) std::cout << " "; // разделитель между числами
    }
    //числа на четных позициях:
    std::cout << std::endl;
    std::cout << "Числа на чётных позициях: ";
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
    //сумма нечетных позиций:
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 != 0) {
            sum += arr[i];
        }
    }
    std::cout << "Сумма элементов, стоящих на нечетных позициях: " << sum << std::endl;
    return 0;
}
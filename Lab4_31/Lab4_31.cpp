#include <iostream>
#include <windows.h>   // Для SetConsoleCP и SetConsoleOutputCP
#include <locale>      // Для setlocale
#include "Header.h"

int main() {
    // Настройка консоли для русского языка
    SetConsoleCP(65001);         // Кодировка ввода UTF-8
    SetConsoleOutputCP(65001);   // Кодировка вывода UTF-8
    setlocale(LC_ALL, "");       // Установка локали на системную

    // Создание объектов
    Weapon sword("Экскалибур", 50, 7.5); // конструктор с параметрами
    Weapon defaultWeapon;                 // конструктор без параметров

    // Вывод данных объектов
    std::cout << "Оружие 1:" << std::endl;
    sword.print();
    std::cout << "Оружие 2:" << std::endl;
    defaultWeapon.print();

    // Проверка работы метода isTooHeavy
    double maxWeight = 6.0;
    std::cout << "\nПроверка веса:" << std::endl;
    std::cout << (sword.isTooHeavy(maxWeight) ? "Слишком тяжелое\n" : "Можно поднять\n");
    std::cout << (defaultWeapon.isTooHeavy(maxWeight) ? "Слишком тяжелое\n" : "Можно поднять\n");

    // Проверка методов totalWeight
    std::cout << "\nСуммарный вес оружия:" << std::endl;
    std::cout << "Sword + DefaultWeapon = " << sword.totalWeight(defaultWeapon) << std::endl;
    std::cout << "Sword + 3.5 = " << sword.totalWeight(3.5) << std::endl;

    // Динамический объект
    Weapon* dynamicWeapon = new Weapon("Длинный лук", 30, 4.2);
    std::cout << "\nДинамический объект:" << std::endl;
    dynamicWeapon->print();

    // Освобождение динамического объекта
    delete dynamicWeapon;

    return 0;
}

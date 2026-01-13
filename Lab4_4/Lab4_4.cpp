#include <iostream>
#include <windows.h>
#include <locale>
#include "Header.h"

int main() {
    // Настройка консоли для русского языка
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    // --- Работа с оружием ---
    Weapon sword("Экскалибур", 50, 7.5);
    Weapon defaultWeapon;

    sword.print();
    defaultWeapon.print();

    // GET и SET
    std::cout << "\nGET-методы:" << std::endl;
    std::cout << "Название: " << sword.getName()
        << ", Урон: " << sword.getDamage()
        << ", Вес: " << sword.getWeight() << std::endl;

    sword.setDamage(60);
    std::cout << "После изменения урона (setDamage): " << sword.getDamage() << std::endl;

    // --- Работа с Characteristic ---
    Characteristic hero(20);
    int totalDamage = hero.GetDamage(sword);
    std::cout << "\nСуммарный урон с учетом силы героя: " << totalDamage << std::endl;

    // --- Работа со статическими методами MyMath ---
    std::cout << "\nРабота со статическими методами MyMath:" << std::endl;
    std::cout << "Add(5, 3) = " << MyMath::Add(5, 3) << std::endl;
    std::cout << "Sub(10, 4) = " << MyMath::Sub(10, 4) << std::endl;
    std::cout << "Mult(2, 6) = " << MyMath::Mult(2, 6) << std::endl;
    std::cout << "Div(10, 2) = " << MyMath::Div(10, 2) << std::endl;

    std::cout << "\nКоличество вызовов методов MyMath: " << MyMath::callCount << std::endl;

    return 0;
}

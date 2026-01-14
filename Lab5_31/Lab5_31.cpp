#include <iostream>
#include <windows.h>
#include <locale.h>

#include "MagicWeapon.h"
#include "DisposableWeapon.h"
#include "Hands.h"

int main() {
    // Настройка консоли для русского языка
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    // Пример: нельзя создать объект абстрактного класса
    // Weapon w; // ❌ ошибка компиляции

    // Магическое оружие
    MagicWeapon staff("Посох", 40, TWOHANDED, 25);
    staff.Attack(); // Вызывается магическая атака
    std::cout << "Урон: " << staff.getDamage() << std::endl; // Базовый + магический

    std::cout << "----------------" << std::endl;

    // Одноразовое оружие
    DisposableWeapon grenade("Граната", 100, ONEHANDED);
    grenade.Attack(); // Первый раз
    grenade.Attack(); // Второй раз — уже использовано

    std::cout << "----------------" << std::endl;

    // Шаблонный класс Hands
    Hands<int, int> ids(10, 20);
    std::cout << "Левая рука (int): " << ids.getLeft()
        << ", правая рука (int): " << ids.getRight() << std::endl;

    return 0;
}

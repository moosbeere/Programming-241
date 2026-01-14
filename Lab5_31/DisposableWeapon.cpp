#include "DisposableWeapon.h"
#include <iostream>

// Конструктор по умолчанию
DisposableWeapon::DisposableWeapon()
    : Weapon(), used(false) {
}

// Конструктор с параметрами
DisposableWeapon::DisposableWeapon(const std::string& n, int d, WeaponType t)
    : Weapon(n, d, t), used(false) {
}

// Переопределение Attack()
void DisposableWeapon::Attack() {
    if (used) {
        // Если оружие уже применили
        std::cout << "Оружие уже было использовано" << std::endl;
    }
    else {
        // Первый раз атакуем
        std::cout << "Атакуем одноразовым оружием" << std::endl;
        used = true; // Помечаем как использованное
    }
}

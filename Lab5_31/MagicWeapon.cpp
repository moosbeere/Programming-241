#include "MagicWeapon.h"
#include <iostream>

// Конструктор по умолчанию
MagicWeapon::MagicWeapon()
    : Weapon(), additionalDamage(0) {
}

// Конструктор с параметрами
MagicWeapon::MagicWeapon(const std::string& n, int d, WeaponType t, int addD)
    : Weapon(n, d, t), additionalDamage(addD) {
}

// Геттер дополнительного урона
int MagicWeapon::getAdditionalDamage() const {
    return additionalDamage;
}

// Переопределение getDamage() для магического оружия
int MagicWeapon::getDamage() const {
    // Суммируем базовый урон + магический
    return Weapon::getDamage() + additionalDamage;
}

// Переопределение Attack()
void MagicWeapon::Attack() {
    std::cout << "Атакуем магическим оружием" << std::endl;
}

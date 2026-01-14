#include "Weapon.h"

// Конструктор по умолчанию
Weapon::Weapon() : name("Без имени"), damage(0), type(ONEHANDED) {}

// Конструктор с параметрами
Weapon::Weapon(const std::string& n, int d, WeaponType t)
    : name(n), damage(d), type(t) {
}

// Возвращает имя оружия
std::string Weapon::getName() const {
    return name;
}

// Возвращает тип оружия
WeaponType Weapon::getType() const {
    return type;
}

// Возвращает базовый урон (можно переопределить)
int Weapon::getDamage() const {
    return damage;
}

// Оператор "больше" по урону
bool Weapon::operator>(const Weapon& other) const {
    return getDamage() > other.getDamage();
}

// Оператор "меньше" по урону
bool Weapon::operator<(const Weapon& other) const {
    return getDamage() < other.getDamage();
}

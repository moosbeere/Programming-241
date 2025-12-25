#include "weapon.h"

// Конструктор Weapon
Weapon::Weapon(string name, int damage, float weight, WeaponType type)
    : name(name), damage(damage), weight(weight), type(type) {
}

Weapon::Weapon() : Weapon("Меч-кладенец", 50, 3.5f, ONEHANDED) {}

// Деструктор
Weapon::~Weapon() {
    cout << "Удаляется оружие: " << name << endl;
}

// Остальные методы Weapon остаются как были
bool Weapon::canLift(float maxWeight) const {
    return weight > maxWeight;
}

float Weapon::getTotalWeight(float otherWeight) const {
    return weight + otherWeight;
}

float Weapon::getTotalWeight(const Weapon& otherWeapon) const {
    return getTotalWeight(otherWeapon.weight);
}

bool Weapon::operator>(const Weapon& other) const {
    return this->getDamage() > other.getDamage();
}

bool Weapon::operator<(const Weapon& other) const {
    return this->getDamage() < other.getDamage();
}

// Конструктор MagicWeapon
MagicWeapon::MagicWeapon(string name, int damage, float weight,
    WeaponType type, int extraDamage)
    : Weapon(name, damage, weight, type), extraDamage(extraDamage) {
}

MagicWeapon::MagicWeapon()
    : MagicWeapon("Волшебный посох", 20, 2.0f, TWOHANDED, 15) {
}

// Метод getDamage для MagicWeapon
int MagicWeapon::getDamage() const {
    return Weapon::getDamage() + extraDamage;
}

// 2. Реализация Attack для MagicWeapon
void MagicWeapon::Attack() {
    cout << name << ": Атакуем магическим оружием!" << endl;
}

// Конструктор DisposableWeapon
DisposableWeapon::DisposableWeapon(string name, int damage, float weight, WeaponType type)
    : Weapon(name, damage, weight, type), used(false) {
}

DisposableWeapon::DisposableWeapon()
    : DisposableWeapon("Одноразовый кинжал", 40, 1.2f, ONEHANDED) {
}

// 7. Реализация Attack для DisposableWeapon
void DisposableWeapon::Attack() {
    if (used) {
        cout << name << ": Оружие уже было использовано!" << endl;
    }
    else {
        cout << name << ": Атакуем одноразовым оружием!" << endl;
        used = true;  // Помечаем как использованное
    }
}
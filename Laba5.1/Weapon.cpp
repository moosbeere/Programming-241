#include "weapon.h"


Weapon::Weapon(string name, int damage, float weight, WeaponType type)
    : name(name), damage(damage), weight(weight), type(type) {
    cout << "Создано оружие: " << name << " (тип: " << type << ")" << endl;
}


Weapon::Weapon(string name, int damage, float weight)
    : Weapon(name, damage, weight, ONEHANDED) {
}  

Weapon::Weapon() : Weapon("Меч-кладенец", 50, 3.5f, ONEHANDED) {}


Weapon::~Weapon() {
    cout << "\nУдаляется оружие: " << name;
    cout << " (тип: " << type << ")" << endl;
}


bool Weapon::canLift(float maxWeight) const {
    return weight > maxWeight;
}


float Weapon::getTotalWeight(float otherWeight) const {
    return weight + otherWeight;
}


float Weapon::getTotalWeight(const Weapon& otherWeapon) const {
    return getTotalWeight(otherWeapon.weight);
}

// 15. Оператор > (больше)
bool Weapon::operator>(const Weapon& other) const {
    return this->getDamage() > other.getDamage();
}

// 15. Оператор < (меньше)
bool Weapon::operator<(const Weapon& other) const {
    return this->getDamage() < other.getDamage();
}

// 9. Конструктор магического оружия с параметрами
MagicWeapon::MagicWeapon(string name, int damage, float weight, WeaponType type, int extraDamage)
    : Weapon(name, damage, weight, type), extraDamage(extraDamage) {
    cout << "Создано МАГИЧЕСКОЕ оружие: " << name
        << " (+" << extraDamage << " магического урона)" << endl;
}

// 9. Конструктор магического оружия без параметров
MagicWeapon::MagicWeapon()
    : MagicWeapon("Посох мага", 30, 2.5f, TWOHANDED, 20) {
}

// 13. Переопределенный метод получения урона
int MagicWeapon::getDamage() const {
    return Weapon::getDamage() + extraDamage;  // Базовый урон + магический
}
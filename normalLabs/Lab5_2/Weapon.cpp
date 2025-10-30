#include "Weapon.h"

// Конструктор с аргументами
Weapon::Weapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
    type = inputType;
}
// Пустой конструктор с дефолтными значениями
Weapon::Weapon() : Weapon("Посох", 1.00, 5.25, ONEHANDED) {}

Weapon::~Weapon() {
    cout << "Удаление оружия";
    printInfo();
}

string Weapon::getName() {
    return name;
}

float Weapon::getDamage() {
    return damage;
}

float Weapon::getWeight() {
    return weight;
}
WeaponType Weapon::getType() {
    return type;
}

void Weapon::setDamage(float newDamage) { damage = newDamage; }

void Weapon::printInfo()
{
    cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl << "Тип оружия: " << type << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}
ostream& operator<<(ostream& os, const Weapon& weapon) {
    os << weapon.name << endl;
    return os;
}

// Аргумент выступает в виде ссылки на объект класса, потому что иначе срабатывает деконструктор на передаваемый элемент
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}
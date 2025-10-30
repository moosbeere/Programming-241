#include "Weapon.h"

// Конструктор с аргументами
Weapon::Weapon(string inputName, float inputDamage, float inputWeight)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
}
// Пустой конструктор с дефолтными значениями
Weapon::Weapon() : Weapon("Посох", 1.00, 5.25) {}

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

void Weapon::setDamage(float newDamage) { damage = newDamage; }

void Weapon::printInfo()
{
    cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}

// Аргумент выступает в виде ссылки на объект класса, потому что иначе срабатывает деконструктор на передаваемый элемент
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}
#include "weapon.h"
#include <iostream>

using namespace std;


Weapon::Weapon(string name, int damage, float weight)
    : name(name), damage(damage), weight(weight) {
    cout << "Создано оружие: " << name << endl;
}


Weapon::Weapon() : Weapon("Меч-кладенец", 50, 3.5f) {}


Weapon::~Weapon() {
    cout << "\nУдаляется оружие:";
    cout << "\n  Название: " << name;
    cout << "\n  Урон: " << damage;
    cout << "\n  Вес: " << weight << endl;
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
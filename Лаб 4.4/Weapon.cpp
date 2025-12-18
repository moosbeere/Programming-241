#include "Weapon.h"
#include <iostream>

Weapon::Weapon(string n, int d, int w) {
    name = n;
    damage = d;
    weight = w;
}

Weapon::~Weapon() {
    cout << "Удаление оружия: " << name
        << " (урон: " << damage
        << ", вес: " << weight << ")" << endl;
}

bool Weapon::canLift(int maxWeight) {
    return weight > maxWeight;
}

float Weapon::totalWeight(float w) {
    return weight + w;
}

float Weapon::totalWeight(const Weapon& other) {
    return totalWeight(other.weight);
}

string Weapon::getName() const { return name; }
int Weapon::getDamage() const { return damage; }
float Weapon::getWeight() const { return weight; }

void Weapon::setDamage(int d) { damage = d; }

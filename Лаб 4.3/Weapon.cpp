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

float Weapon::totalWeight(const Weapon& x) {
    return totalWeight(x.weight);
}

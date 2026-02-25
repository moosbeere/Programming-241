#include "lab4.4.2.h"
#include <iostream>

Weapon::Weapon(const std::string &weaponName, int weaponDamage,
               float weaponWeight) {
  name = weaponName;
  damage = weaponDamage;
  weight = weaponWeight;
}

Weapon::Weapon() : Weapon("Меч", 10, 2.5f) {}

Weapon::~Weapon() {
  std::cout << "Удаляется: " << std::endl;
  display();
}

void Weapon::display() const {
  std::cout << "Оружие: " << name << ", Урон: " << damage << ", Вес: " << weight
            << " кг" << std::endl;
}

bool Weapon::tooHeavy(float maxWeight) const { return weight > maxWeight; }

float Weapon::totalWeight(const Weapon &otherWeapon) const {
  return totalWeight(otherWeapon.weight);
}

float Weapon::totalWeight(float otherWeight) const {
  return weight + otherWeight;
}

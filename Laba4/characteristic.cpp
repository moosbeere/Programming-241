#include "characteristic.h"

Characteristic::Characteristic(int strength) : strength(strength) {}

int Characteristic::GetDamage(const Weapon& weapon) const {
    return strength + weapon.getDamage();
}
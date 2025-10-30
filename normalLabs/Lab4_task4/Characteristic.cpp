#include "Characteristic.h"

Characteristic::Characteristic(float inputStrength) {
    strength = inputStrength;
}

float Characteristic::GetDamage(const Weapon& weapon) {
    return strength + weapon.damage;
}
#include "Characteristic.h"
#include "Weapon.h"

Characteristic::Characteristic(int s) {
    strength = s;
}

int Characteristic::GetDamage(const Weapon& w) {
    return strength + w.damage;
}

#include "lab4.4.3.h"

int Characteristic::getDamage(const Weapon &weapon) const {
  return strength + weapon.damage;
}

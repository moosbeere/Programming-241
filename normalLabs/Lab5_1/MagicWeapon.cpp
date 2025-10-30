#include "MagicWeapon.h"

float MagicWeapon::getExtraDamage() { return extraDamage; }
float MagicWeapon::getTotalDamage() { return extraDamage + damage; }
float MagicWeapon::getDamage() { return extraDamage + Weapon::getDamage(); }
bool MagicWeapon::operator<(Weapon& other) { return this->getDamage() < other.getDamage(); }
bool MagicWeapon::operator>(Weapon& other) { return this->getDamage() > other.getDamage(); }
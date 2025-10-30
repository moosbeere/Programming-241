#include "MagicWeapon.h"

float MagicWeapon::getExtraDamage() { return extraDamage; }
float MagicWeapon::getTotalDamage() { return extraDamage + damage; }
float MagicWeapon::getDamage() { return extraDamage + Weapon::getDamage(); }
void MagicWeapon::Attack() {
    cout << "Атака!" << endl;
}
ostream& operator<<(ostream& os, const MagicWeapon& weapon) {
    os << weapon.name << " (магическое)";
    return os;
}
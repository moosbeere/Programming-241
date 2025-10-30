#include "OneTimeWeapon.h"

void OneTimeWeapon::Attack() {
    if (used) { cout << "Оружие уже было использовано!" << endl; }
    else {
        used = true;
        cout << "Атакуем одноразовым оружием!" << endl;
    }
}
ostream& operator<<(ostream& os, const OneTimeWeapon& weapon) {
    os << weapon.name << (weapon.used ? " (использовано)" : " (новое)");
    return os;
}
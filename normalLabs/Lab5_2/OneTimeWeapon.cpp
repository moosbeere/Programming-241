#include "OneTimeWeapon.h"

void OneTimeWeapon::Attack() {
    if (used) { cout << "������ ��� ���� ������������!" << endl; }
    else {
        used = true;
        cout << "������� ����������� �������!" << endl;
    }
}
ostream& operator<<(ostream& os, const OneTimeWeapon& weapon) {
    os << weapon.name << (weapon.used ? " (������������)" : " (�����)");
    return os;
}
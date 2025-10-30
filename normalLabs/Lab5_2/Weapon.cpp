#include "Weapon.h"

// ����������� � �����������
Weapon::Weapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
    type = inputType;
}
// ������ ����������� � ���������� ����������
Weapon::Weapon() : Weapon("�����", 1.00, 5.25, ONEHANDED) {}

Weapon::~Weapon() {
    cout << "�������� ������";
    printInfo();
}

string Weapon::getName() {
    return name;
}

float Weapon::getDamage() {
    return damage;
}

float Weapon::getWeight() {
    return weight;
}
WeaponType Weapon::getType() {
    return type;
}

void Weapon::setDamage(float newDamage) { damage = newDamage; }

void Weapon::printInfo()
{
    cout << "\n���: " << name << endl << "����: " << damage << endl << "���: " << weight << endl << "��� ������: " << type << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}
ostream& operator<<(ostream& os, const Weapon& weapon) {
    os << weapon.name << endl;
    return os;
}

// �������� ��������� � ���� ������ �� ������ ������, ������ ��� ����� ����������� ������������� �� ������������ �������
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}
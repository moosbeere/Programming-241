#include "Weapon.h"

// ����������� � �����������
Weapon::Weapon(string inputName, float inputDamage, float inputWeight)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
}
// ������ ����������� � ���������� ����������
Weapon::Weapon() : Weapon("�����", 1.00, 5.25) {}

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

void Weapon::setDamage(float newDamage) { damage = newDamage; }

void Weapon::printInfo()
{
    cout << "\n���: " << name << endl << "����: " << damage << endl << "���: " << weight << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}

// �������� ��������� � ���� ������ �� ������ ������, ������ ��� ����� ����������� ������������� �� ������������ �������
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}
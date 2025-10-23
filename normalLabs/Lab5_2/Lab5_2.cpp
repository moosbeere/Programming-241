#include <iostream>
#include "Weapon.h"
#include "MagicWeapon.h"
#include "OneTimeWeapon.h"
#include "Hands.h"


using namespace std;

// Конструктор с аргументами
Weapon::Weapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType)
{
    name = inputName;
    damage = inputDamage;
    weight = inputWeight;
    type = inputType;
}
// Пустой конструктор с дефолтными значениями
Weapon::Weapon() : Weapon("Посох", 1.00, 5.25, ONEHANDED) {}

Weapon::~Weapon() {
    cout << "Удаление оружия";
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
    cout << "\nИмя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << endl << "Тип оружия: " << type << endl;
}

bool Weapon::checkWeight(float maxWeight) {
    if (maxWeight > weight) { return true; }
    else { return false; }
}

// Аргумент выступает в виде ссылки на объект класса, потому что иначе срабатывает деконструктор на передаваемый элемент
int Weapon::newWeapon(Weapon& newItem) {
    return newWeapon(newItem.weight);
}
int Weapon::newWeapon(int newWeight) {
    return newWeight + weight;
}

float MagicWeapon::getExtraDamage() { return extraDamage; }
float MagicWeapon::getTotalDamage() { return extraDamage + damage; }
float MagicWeapon::getDamage() { return extraDamage + Weapon::getDamage(); }
void MagicWeapon::Attack() {
    cout << "Атака!" << endl;
}

void OneTimeWeapon::Attack() {
    if (used) { cout << "Оружие уже было использовано!" << endl; }
    else {
        used = true;
        cout << "Атакуем одноразовым оружием!" << endl;
    }
}
ostream& operator<<(ostream& os, const Weapon& weapon) {
    os << weapon.name << endl;
    return os;
}
ostream& operator<<(ostream& os, const MagicWeapon& weapon) {
    os << weapon.name << " (магическое)";
    return os;
}
ostream& operator<<(ostream& os, const OneTimeWeapon& weapon) {
    os << weapon.name << (weapon.used ? " (использовано)" : " (новое)");
    return os;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // Weapon sword; вылезает ошибка, невозможно создать экземпляр абстрактного класса
    MagicWeapon sword;
    sword.printInfo();
    cout << endl;
    sword.Attack();
    OneTimeWeapon mushket = OneTimeWeapon("Мушкет", 10, 5, CROSSBOW);
    mushket.Attack();
    mushket.Attack();

    // Из-за того что мы можем передать любой тип в Hands мы должны перегрузить оператор <<
    // Во всех классах оружия (не только в Weapon, потому что он абстрактный)
    // Поэтому мы везде создаём friend ostream& operator<<
    // которая возвращает поток, чтобы можно было делать вывод по дочерним классам оружия
    Hands<OneTimeWeapon, MagicWeapon> weapons(mushket, sword);
    weapons.printHands();
    cout << endl;

    Hands<int, int> weaponn(1, 2);
    weaponn.printHands();
    cout << endl;
}
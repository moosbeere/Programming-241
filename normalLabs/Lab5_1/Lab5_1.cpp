#include <iostream>
#include "Weapon.h"
#include "MagicWeapon.h"


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
bool MagicWeapon::operator<(Weapon& other) { return this->getDamage() < other.getDamage(); }
bool MagicWeapon::operator>(Weapon& other) { return this->getDamage() > other.getDamage(); }

void Player::printAll() {
    cout << "ID: " << id << endl;
    cout << "Login: " << login << endl;
    cout << "Пароль: " << password << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 25, 2, ONEHANDED);
    sword.printInfo();

    Weapon axe("Топор", 15, 7, TWOHANDED);
    axe.printInfo();
    Weapon* bow = new Weapon("Лук", 10, 0.1, BOW);
    bow->printInfo();


    if (sword.getType() == ONEHANDED) {
        cout << endl << sword.getName() << " - это одноручное оружие" << endl;
    }
    Player player;
    player.id = 1;
    player.login = "login";
    player.password = "password";
    player.printAll();
    cout << endl;

    MagicWeapon ump = MagicWeapon("Пистолет-пулемет", 14, 2, CROSSBOW, 10);
    ump.printInfo();
    cout << "Общий урон: " << ump.getDamage() << endl;
    cout << "Дополнительный магический урон: " << ump.getExtraDamage() << endl;
    cout << endl;

    MagicWeapon magicSword("Магический меч", 10, 2, ONEHANDED, 10);
    magicSword.printInfo();
    cout << "Общий урон: " << magicSword.getDamage() << endl;


    cout << "Урон Пистолет-пулемета > магического меча: " << (ump > magicSword ? "Да" : "Нет") << endl;
    cout << "Урон пистолета-пулемета > меча: " << (ump > sword ? "Да" : "Нет") << endl;
    delete bow;
}
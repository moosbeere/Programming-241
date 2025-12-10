#include "weapon.h"

// Конструктор с параметрами
weapon::weapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype)
{
    name = Wname;
    weight = Wweight;
    damage = Wdamage;
    type = Wtype;  // Инициализация типа
}

// Конструктор по умолчанию
weapon::weapon() : weapon("палка", 1, 100000, ONEHANDED) {}

// Виртуальный деструктор
weapon::~weapon() {
    cout << "УДАЛЕНИЕ ОРУЖИЯ" << "\n";
    cout << "Название: " << name << "\n";
    cout << "Тип: " << getWeaponTypeName(type) << "\n";
    cout << "Урон: " << damage << "\n";
    cout << "Вес: " << weight << "\n\n";
}

string weapon::getName() const {
    return name;
}

WeaponType weapon::getType() const {
    return type;
}

void weapon::print()
{
    cout << "Название: " << name << "\n";
    cout << "Вес: " << weight << "\n";
    cout << "Урон: " << damage << "\n";
    cout << "Тип: " << getWeaponTypeName(type) << "\n\n";
}

int weapon::weight_possible() const
{
    return weight < 50;
}

int weapon::getweight() const {
    return weight;
}

int weapon::getdamage() const {
    return damage;
}

void weapon::setdamage(int newdamage) {
    damage = newdamage;
}

void weapon::setType(WeaponType newType) {
    type = newType;
}

int weapon::suma_weight(const weapon& oweapon) const {
    return weight + oweapon.getweight();
}

int weapon::suma_weight2(int oweight) const {
    return weight + oweight;
}

int weapon::suma_weight3(const weapon& oweapon) const {
    return suma_weight2(oweapon.getweight());
}


bool weapon::operator>(const weapon& other) const {
    return this->getdamage() > other.getdamage();
}

bool weapon::operator<(const weapon& other) const {
    return this->getdamage() < other.getdamage();
}


void Player::printPlayer() const {
    cout << "ID игрока: " << id << "\n";
    cout << "Логин: " << login << "\n";
    cout << "Пароль: " << password << "\n\n";
}


MagicWeapon::MagicWeapon(string Wname, int Wweight, int Wdamage, int addDamage, WeaponType Wtype)
    : weapon(Wname, Wweight, Wdamage, Wtype), additionalDamage(addDamage) {
}

MagicWeapon::MagicWeapon() : weapon("магическая палка", 2, 50000), additionalDamage(1000) {}


int MagicWeapon::getAdditionalDamage() const {
    return additionalDamage;
}

int MagicWeapon::getdamage() const {
    return weapon::getdamage() + additionalDamage; 
}

Characteristic::Characteristic(int str) : strength(str) {}

int Characteristic::getStrength() const {
    return strength;
}

int Characteristic::GetDamage(const weapon& w) const {
    return strength + w.getdamage();  
}


string getWeaponTypeName(WeaponType type) {
    switch (type) {
    case ONEHANDED: return "одноручное";
    case TWOHANDED: return "двуручное";
    case BOW: return "лук";
    case CROSSBOW: return "арбалет";
    default: return "неизвестно";
    }
}
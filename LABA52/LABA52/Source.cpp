#include "Header.h"

weapon::weapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype)
    : name(Wname), weight(Wweight), damage(Wdamage), type(Wtype) {
}

weapon::weapon() : weapon("палка", 1, 10, ONEHANDED) {}

weapon::~weapon() {
    cout << "Удаление оружия: " << name << "\n";
}

string weapon::getName() const { return name; }
WeaponType weapon::getType() const { return type; }
int weapon::getweight() const { return weight; }
int weapon::getdamage() const { return damage; }

void weapon::print() const {
    cout << "Название: " << name
        << ", Вес: " << weight
        << ", Урон: " << damage
        << ", Тип: " << getWeaponTypeName(type) << "\n";
}

int weapon::weight_possible() const { return weight < 50; }
void weapon::setdamage(int newdamage) { damage = newdamage; }
void weapon::setType(WeaponType newType) { type = newType; }
int weapon::suma_weight(const weapon& oweapon) const { return weight + oweapon.getweight(); }
int weapon::suma_weight2(int oweight) const { return weight + oweight; }
int weapon::suma_weight3(const weapon& oweapon) const { return suma_weight2(oweapon.getweight()); }
bool weapon::operator>(const weapon& other) const { return this->getdamage() > other.getdamage(); }
bool weapon::operator<(const weapon& other) const { return this->getdamage() < other.getdamage(); }

void Player::printPlayer() const {
    cout << "ID игрока: " << id << "\n";
    cout << "Логин: " << login << "\n";
    cout << "Пароль: " << password << "\n\n";
}

MagicWeapon::MagicWeapon(string Wname, int Wweight, int Wdamage, int addDamage, WeaponType Wtype)
    : weapon(Wname, Wweight, Wdamage, Wtype), additionalDamage(addDamage) {
}

MagicWeapon::MagicWeapon() : weapon("магическая палка", 2, 50, ONEHANDED), additionalDamage(10) {}

int MagicWeapon::getAdditionalDamage() const { return additionalDamage; }
int MagicWeapon::getdamage() const { return weapon::getdamage() + additionalDamage; }

void MagicWeapon::Attack() {
    cout << "Атакуем магическим оружием" << endl;
}

DisposableWeapon::DisposableWeapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype)
    : weapon(Wname, Wweight, Wdamage, Wtype), used(false) {
}

DisposableWeapon::DisposableWeapon() : weapon("одноразовый кинжал", 1, 5, ONEHANDED), used(false) {}

int DisposableWeapon::getdamage() const { return weapon::getdamage(); }

void DisposableWeapon::Attack() {
    if (used)
        cout << "Оружие уже было использовано" << endl;
    else {
        cout << "Атакуем одноразовым оружием" << endl;
        used = true;
    }
}

bool DisposableWeapon::isUsed() const { return used; }
void DisposableWeapon::reset() { used = false; }

Characteristic::Characteristic(int str) : strength(str) {}
int Characteristic::getStrength() const { return strength; }
int Characteristic::GetDamage(const weapon& w) const { return strength + w.getdamage(); }


template<typename TLeft, typename TRight>
DualWield<TLeft, TRight>::DualWield(const TLeft& left, const TRight& right)
    : leftHand(left), rightHand(right) {
}

template<typename TLeft, typename TRight>
TLeft DualWield<TLeft, TRight>::getLeftHand() const { return leftHand; }

template<typename TLeft, typename TRight>
void DualWield<TLeft, TRight>::setLeftHand(const TLeft& left) { leftHand = left; }

template<typename TLeft, typename TRight>
TRight DualWield<TLeft, TRight>::getRightHand() const { return rightHand; }

template<typename TLeft, typename TRight>
void DualWield<TLeft, TRight>::setRightHand(const TRight& right) { rightHand = right; }

string getWeaponTypeName(WeaponType type) {
    switch (type) {
    case ONEHANDED: return "одноручное";
    case TWOHANDED: return "двуручное";
    case BOW: return "лук";
    case CROSSBOW: return "арбалет";
    default: return "неизвестно";
    }
}
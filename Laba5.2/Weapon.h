#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

using namespace std;

// Перечисление типов оружия
enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};


class Weapon {
protected:
    string name;
    int damage;
    float weight;
    WeaponType type;

public:
    Weapon(string name, int damage, float weight, WeaponType type);
    Weapon();
    virtual ~Weapon();

    // 1. Чисто виртуальная функция (делает класс абстрактным)
    virtual void Attack() = 0;

    bool canLift(float maxWeight) const;
    float getTotalWeight(const Weapon& otherWeapon) const;
    float getTotalWeight(float otherWeight) const;

    string getName() const { return name; }
    virtual int getDamage() const { return damage; }
    float getWeight() const { return weight; }
    WeaponType getType() const { return type; }

    void setDamage(int newDamage) { damage = newDamage; }

    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;

};

// 2. MagicWeapon реализует Attack
class MagicWeapon : public Weapon {
private:
    int extraDamage;

public:
    MagicWeapon(string name, int damage, float weight, WeaponType type, int extraDamage);
    MagicWeapon();

    int getExtraDamage() const { return extraDamage; }
    int getDamage() const override;

    // 4. Реализация виртуального метода Attack
    void Attack() override;
};

// 5. Класс одноразового оружия
class DisposableWeapon : public Weapon {
private:
    bool used;  // 6. Флаг использования

public:
    DisposableWeapon(string name, int damage, float weight, WeaponType type);
    DisposableWeapon();

    bool isUsed() const { return used; }

    // 7. Реализация Attack с проверкой флага
    void Attack() override;
};

// 9. Шаблон класса для хранения оружия в обеих руках
template<typename TLeft, typename TRight>
class DualWield {
private:
    TLeft leftHand;
    TRight rightHand;

public:
    // 10. Конструктор
    DualWield(const TLeft& left, const TRight& right)
        : leftHand(left), rightHand(right) {
    }

    // 10. GET и SET методы
    TLeft getLeft() const { return leftHand; }
    void setLeft(const TLeft& left) { leftHand = left; }

    TRight getRight() const { return rightHand; }
    void setRight(const TRight& right) { rightHand = right; }

    // Метод для вывода информации
    void print() const {
        cout << "Левая рука: " << leftHand << endl;
        cout << "Правая рука: " << rightHand << endl;
    }
};

#endif
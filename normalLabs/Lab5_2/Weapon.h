#pragma once
#include <iostream>


using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon
{
protected:
    string name;
    float damage;
    float weight;
    WeaponType type;
public:
    Weapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType);
    Weapon();

    virtual ~Weapon();

    // get методы
    string getName();
    float getDamage();
    float getWeight();
    WeaponType getType();

    // set метод для урона
    virtual void setDamage(float newDamage);

    virtual void printInfo();

    virtual bool checkWeight(float maxWeight);

    virtual int newWeapon(Weapon& newItem);

    virtual int newWeapon(int newWeight);
    virtual void Attack() = 0;

    friend ostream& operator<<(ostream& os, const Weapon& weapon);
};

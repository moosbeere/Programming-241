#pragma once

#include <iostream>


using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

struct Player {
    int id;
    string login;
    string password;

    void printAll();
};

class Weapon
{
private:
    string name;
    float damage;
    float weight;
    WeaponType type;
public:
    Weapon(string inputName, float inputDamage, float inputWeight, WeaponType inputType);
    Weapon();

    ~Weapon();

    // get методы
    string getName();
    float getDamage();
    float getWeight();
    WeaponType getType();

    // set метод для урона
    void setDamage(float newDamage);

    void printInfo();

    bool checkWeight(float maxWeight);

    int newWeapon(Weapon& newItem);

    int newWeapon(int newWeight);
    friend class MagicWeapon;
};

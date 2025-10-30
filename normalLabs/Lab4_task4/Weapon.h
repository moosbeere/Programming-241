#pragma once

#include <iostream>


using namespace std;


class Weapon
{
private:
    string name;
    float damage;
    float weight;
public:
    Weapon(string inputName, float inputDamage, float inputWeight);
    Weapon();

    ~Weapon();

    // get методы
    string getName();
    float getDamage();
    float getWeight();

    // set метод для урона
    void setDamage(float newDamage);

    void printInfo();

    bool checkWeight(float maxWeight);

    int newWeapon(Weapon& newItem);

    int newWeapon(int newWeight);
    friend class Characteristic;
};
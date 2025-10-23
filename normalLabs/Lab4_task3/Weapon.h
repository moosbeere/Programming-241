#pragma once

#include <iostream>


using namespace std;


class Weapon
{
public:
    string name;
    float damage;
    float weight;
    Weapon(string inputName, float inputDamage, float inputWeight);
    Weapon();
    ~Weapon();
    void printInfo();
    bool checkWeight(float maxWeight);
    int newWeapon(Weapon& newItem);
    int newWeapon(int newWeight);
};
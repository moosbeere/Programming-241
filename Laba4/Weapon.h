#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Characteristic; 

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    Weapon(string name, int damage, float weight);
    Weapon();

    
    ~Weapon();

    
    bool canLift(float maxWeight) const;
    float getTotalWeight(const Weapon& otherWeapon) const;
    float getTotalWeight(float otherWeight) const;

    
    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }

    
    void setDamage(int newDamage) { damage = newDamage; }

    
    friend class Characteristic;
};

#endif
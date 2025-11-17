#pragma once
#include "Weapon.h"


class MagicWeapon :
    public Weapon
{
    float extra_damage;
public:
    MagicWeapon(std::string name, float damage, float weight, float extra_damage, Specific type);
    MagicWeapon(std::string name, float damage, float weight, float extra_damage);
    MagicWeapon();
    float getExtraDmg();
    void setExtraDmg(float dmg);
    void printAll() override;
    float getDamage() override;
    void attack() override;
    //bool operator> (const MagicWeapon& w2);
};


#pragma once
#include "Weapon.h"


class MagicWeapon :
    public Weapon
{
    float extra_damage;
public:
    MagicWeapon(std::string name, float damage, float weight, float extra_damage);
    MagicWeapon();
    float getExtraDmg();
    void setExtraDmg(float dmg);
};


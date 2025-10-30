#pragma once
#include "Weapon.h"

class Characteristic
{
private:
    float strength;

public:
    Characteristic(float inputStrength);

    float GetDamage(const Weapon& weapon);
};
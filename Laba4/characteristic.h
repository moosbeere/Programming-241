#pragma once
#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include "weapon.h"

class Characteristic {
private:
    int strength;

public:
    Characteristic(int strength);
    int GetDamage(const Weapon& weapon) const;
};

#endif
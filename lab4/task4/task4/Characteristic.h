#pragma once
#include "Weapon.h"

class Weapon;

class Characteristic
{
	int strange;

public:

	Characteristic(int strange);

	float GetDamage(Weapon *w);

};


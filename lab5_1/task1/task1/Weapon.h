#pragma once

#include <string>
#include <iostream>
#include "Specific.cpp"
//#include "MagicWeapon.h"
//#include "Characteristic.h"


class Weapon
{
	std::string name = name;
	float damage = damage;
	float weight = weight;
	Specific type;
	//friend MagicWeapon;
	//friend class Characteristic;
public:

	Weapon(std::string name, float damage, float weight, Specific type);
	Weapon();
	~Weapon();

	float weight_sum(Weapon* w1);
	float weight_sum(float weight);
	bool check_weight(float weight);

	std::string getName();
	float getDamage();
	float getWeight();
	Specific getType();

	void setName(std::string name);
	void setDamage(float dmg);
	void setWeight(float weight);

};

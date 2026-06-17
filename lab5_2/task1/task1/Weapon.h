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
	Weapon(std::string name, float damage, float weight);
	Weapon();
	~Weapon();

	virtual void attack() = 0;
	float weight_sum(Weapon* w1);
	float weight_sum(float weight);
	bool check_weight(float weight);
	std::string getStrType();
	std::string getName();
	virtual float getDamage();
	float getWeight();
	Specific getType();

	void setType(Specific type);
	void setName(std::string name);
	void setDamage(float dmg);
	void setWeight(float weight);
	virtual void printAll();
	bool operator>(Weapon& w2);
	bool operator<(Weapon& w2);
};

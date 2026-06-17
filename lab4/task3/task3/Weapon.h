#pragma once

#include <string>
#include <iostream>

class Weapon
{
public:
	std::string name;
	float damage;
	float weight;

	Weapon(std::string name, float damage, float weight);
	Weapon();
	~Weapon();

	float weight_sum(Weapon *w1);
	float weight_sum(float weight);
	bool check_weight(float weight);

};


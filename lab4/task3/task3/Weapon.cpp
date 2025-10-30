#include "Weapon.h"

Weapon::Weapon(std::string name, float damage, float weight)
{
	this->name = name;
	this->damage = damage;
	this->weight = weight;
}
Weapon::Weapon()
{
	this->name = "MACINEGUN";
	this->damage = 2;
	this->weight = 1;
}

Weapon::~Weapon()
{
	std::cout << "Destructor is activated" << std::endl;
}

bool Weapon::check_weight(float weight)
{
	return (this->weight < weight);
}

float Weapon::weight_sum(float weight) {
	return (weight + this->weight);
}
float Weapon::weight_sum(Weapon *w1)
{
	return (this->weight_sum(w1->weight));
}


;


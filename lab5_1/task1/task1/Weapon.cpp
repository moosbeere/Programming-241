#include "Weapon.h"
//#include "Specific.cpp"


Weapon::Weapon(std::string name, float damage, float weight, Specific type)
{
	this->name = name;
	this->damage = damage;
	this->weight = weight;
	this->type = type;
}
Weapon::Weapon()
{
	this->name = "Long Sword";
	this->damage = 6;
	this->weight = 2;
	this->type = Specific::ONEHANDED;
}

Weapon::~Weapon()
{
	std::cout << "Destructor is activated" << std::endl;
}

Specific Weapon::getType()
{
	return this->type;
}
bool Weapon::check_weight(float weight)
{
	return (this->weight < weight);
}

float Weapon::weight_sum(float weight) {
	return (weight + this->weight);
}
float Weapon::weight_sum(Weapon* w1)
{
	return (this->weight_sum(w1->weight));
}
std::string Weapon::getName()
{
	return this->name;
}
float Weapon::getDamage()
{
	return this->damage;
}
float Weapon::getWeight()
{
	return this->weight;
}
;
void Weapon::setName(std::string name)
{
	this->name = name;
}
void Weapon::setDamage(float dmg) {
	this->damage = dmg;
}
void Weapon::setWeight(float weight) {
	this->weight = weight;
}

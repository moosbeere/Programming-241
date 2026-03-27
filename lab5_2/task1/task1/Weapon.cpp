#include "Weapon.h"
//#include "Specific.cpp"


Weapon::Weapon(std::string name, float damage, float weight, Specific type)
{
	this->name = name;
	this->damage = damage;
	this->weight = weight;
	this->type = type;
}

Weapon::Weapon(std::string name, float damage, float weight)
{
	this->name = name;
	this->damage = damage;
	this->weight = weight;
	this->type = Specific::ONEHANDED;
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
void Weapon::setType(Specific type)
{
	this->type = type;
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
std::string Weapon::getStrType()
{
	std::string str_type;
	switch (type)
	{
	case(Specific::ONEHANDED): {
		str_type = "ONEHANDED";
		break;
	}
	case(Specific::TWOHANDED): {
		str_type = "TWOHANDED";
		break;
	}
	case(Specific::BOW): {
		str_type = "BOW";
		break;
	}
	case(Specific::CROSSBOW): {
		str_type = "CROSSBOW";
		break;
	}
							return str_type;
	}
}
void Weapon::printAll()
{
	std::cout << this->name << "\n[\tdmg=" << damage << "\n\tweight=" << weight << "\n"
		<< "\ttype= " << getStrType() << "\t]" << std::endl;
}
bool Weapon::operator>(Weapon& w2)
{
	std::cout << getName() << " damage is " << getDamage() << "\n" << w2.getName() << " damage is " << w2.getDamage() << std::endl;
	return (getDamage() > w2.getDamage());
}
bool Weapon::operator<(Weapon& w2)
{
	std::cout << getName() << " damage is " << getDamage() << "\n" << w2.getName() << " damage is " << w2.getDamage() << std::endl;
	return (getDamage() < w2.getDamage());
}
#include "OneTimeWeapon.h"


OneTimeWeapon::OneTimeWeapon(std::string name, float damage, float weight)
{
	setName(name);
	setDamage(damage);
	setWeight(weight);
	isUsed = false;
}

OneTimeWeapon::OneTimeWeapon(std::string name, float damage, float weight, Specific type)
{
	setName(name);
	setDamage(damage);
	setWeight(weight);
	setType(type);
	isUsed = false;
}

OneTimeWeapon::OneTimeWeapon() {
	setName("Long Sword");
	setDamage(6);
	setWeight(2);
	setType(Specific::ONEHANDED);
	setIsUsed(false);
}
OneTimeWeapon::~OneTimeWeapon()
{
	std::cout << "Destructor is activated\n";
}
void OneTimeWeapon::setIsUsed(bool status)
{
	this->isUsed = status;
}

bool OneTimeWeapon::getIsUsed()
{
	return this->isUsed;
}

void OneTimeWeapon::attack()
{
	if (!getIsUsed())
	{
		std::cout << "attacking with One-Time Weapon\n";
		setIsUsed(true);
	}
	else std::cout << "The Weapon was used previosly.\n";
}


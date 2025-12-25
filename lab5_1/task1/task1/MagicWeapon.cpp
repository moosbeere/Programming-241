#include "MagicWeapon.h"


MagicWeapon::MagicWeapon(std::string name, float damage, float weight, float extra_damage)
{
	this->setName(name);
	this->setDamage(damage);
	this->setWeight(weight);
	this->extra_damage = extra_damage;
}
MagicWeapon::MagicWeapon()
{
	this->setName("Cedar Staff");
	this->setDamage(3);
	this->setWeight(5);
	this->setExtraDmg(5);
}
float MagicWeapon::getExtraDmg()
{
	return this->extra_damage;
}
void MagicWeapon::setExtraDmg(float dmg)
{
	this->extra_damage = dmg;
}
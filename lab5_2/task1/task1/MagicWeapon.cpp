#include "MagicWeapon.h"


MagicWeapon::MagicWeapon(std::string name, float damage, float weight, float extra_damage, Specific type)
{
	this->setName(name);
	this->setDamage(damage);
	this->setWeight(weight);
	this->extra_damage = extra_damage;
	this->setType(type);
}

MagicWeapon::MagicWeapon(std::string name, float damage, float weight, float extra_damage)
{
	this->setName(name);
	this->setDamage(damage);
	this->setWeight(weight);
	this->extra_damage = extra_damage;
	this->setType(Specific::ONEHANDED);
}
MagicWeapon::MagicWeapon()
{
	this->setName("Cedar Staff");
	this->setDamage(3);
	this->setWeight(5);
	this->setExtraDmg(5);
}
void MagicWeapon::attack()
{
	std::cout << "Attacking with magic weapon\n";
}
float MagicWeapon::getExtraDmg()
{
	return this->extra_damage;
}
void MagicWeapon::setExtraDmg(float dmg)
{
	this->extra_damage = dmg;
}
void MagicWeapon::printAll()
{
	//Weapon::printAll();
	std::cout << getName() << "\n[\tdmg=" << Weapon::getDamage() << "\n\textra dmg=" << getExtraDmg() << "\n\tweight=" << getWeight() << "\n\ttype= " << getStrType() << "\t]" << std::endl;

	//std::cout << "& Extra dmg= " << extra_damage << std::endl;
}

float MagicWeapon::getDamage()
{
	return (Weapon::getDamage() + getExtraDmg());
}

//bool MagicWeapon::operator> (const MagicWeapon & w2)
//{
	//return (getDamage() > w2.getDamage());
//}

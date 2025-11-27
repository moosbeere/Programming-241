#include "FlyMonster.h"
#include <iostream>
using namespace std;
FlyMonster::FlyMonster(string name, double health, float maxHealth, float damage, float flySpeed):Monster(name, health, maxHealth, damage)
{
	this->flySpeed = flySpeed;
}

FlyMonster::FlyMonster() :FlyMonster("FlyMonster", 1, 1, 1, 1){}

void FlyMonster::fly()
{
	setHealth(getHealth() - 1);
	std::cout << name << " is flying\n";
}

float FlyMonster::getFlySpeed()
{
	return flySpeed;
}

void FlyMonster:: print() {
	Monster::print();
	cout << "FlySpeed: " << flySpeed << endl;
}

FlyMonster FlyMonster::operator+(FlyMonster& m2)
{
	return FlyMonster(this->name, this->getHealth(), this->getMaxHealth() + m2.getMaxHealth(),
		this->getDamage() + m2.getDamage(), this->flySpeed + m2.flySpeed);
}

bool FlyMonster::operator ==(FlyMonster& m2)
{
	return this->name == m2.getName();
}
bool FlyMonster::operator !=(FlyMonster& m2)
{
	return this->name != m2.getName();
}

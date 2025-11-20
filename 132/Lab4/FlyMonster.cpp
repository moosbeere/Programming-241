#include "FlyMonster.h"
#include <iostream>

FlyMonster::FlyMonster(string name, float health, float maxHealth, float damage, float flySpeed):Monster(name, health, maxHealth, damage)
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


#include "Monster.h"

Monster::Monster(string name, float health, float maxHealth, float damage):name(name), health(health),maxHealth(maxHealth),damage(damage){}

Monster::Monster():Monster("Default",6,8,3){}

Monster::~Monster()
{
	std::cout << name << "destroyed" << std::endl;
}

float Monster::getLevel()
{
	return maxHealth / 5;
}

void Monster::applyDamage(float damage)
{
	health -= damage;
}

void Monster::applyDamage()
{
	applyDamage(1);
}

void Monster::recovery()
{
	health = maxHealth;
}

void Monster::attack(Monster& m)
{
	m.applyDamage(damage);
}




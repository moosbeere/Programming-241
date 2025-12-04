#include "Monster.h"
#include <iostream>
#include <string>
#include <sstream>

void Monster::printWarning(string msg)
{
	std::cout << "Warning: " << msg << std::endl;
}

Monster::Monster(string name, double health, float maxHealth, float damage):name(name), health(health),maxHealth(maxHealth),damage(damage){
	counter++;
}

Monster::Monster():Monster("Default",6,8,3){}

Monster::~Monster()
{
	std::cout << name << "destroyed" << std::endl;
}

void Monster::resetCounter()
{
	counter = 0;
}

string Monster::getName()
{
	return name;
}

double Monster::getHealth()
{
	return health;
}

float Monster::getDamage()
{
	return damage;
}

float Monster::getMaxHealth()
{
	return maxHealth;
}

void Monster::setHealth(double health)
{
	if (health > this->maxHealth) this->health = maxHealth;
	else if (health >= 0) this->health = health;
	else printWarning("health < 0");
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

void Monster::print()
{
	cout << "Name: " << name << endl;
	cout << "Max health: " << maxHealth << endl;
	cout << "Health: " << health << endl;
	cout << "Damage: " << damage << endl;
}

Monster::operator string() const
{
	//this->name = "New name"; ошибка изменения объекта
	std::stringstream result;
	result << name << " " << health;
	return result.str();
}




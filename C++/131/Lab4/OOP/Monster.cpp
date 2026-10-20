#include "Monster.h"

Monster::Monster(std::string name, float health, float maxHealth, float damage) :name(name), health(health), maxHealth(maxHealth), damage(damage){
    counter++;
}

Monster::Monster():Monster("Goblin", 4, 7, 4) {}

float Monster::getLevel()
{
    return maxHealth / 5;
}

void Monster::resetCounter()
{
    counter = 0;
}

void Monster::applyDamage(float damage) {
    health -= damage;
}
void Monster::applyDamage() {
    applyDamage(1);
}
void Monster::recovery() {
    health = maxHealth;
}
void Monster::attack(Monster& m) {
    m.applyDamage(damage);
}

void Monster::setName(string name)
{
    this->name = name;
}

void Monster::setHealth(float health)
{
    if (health > maxHealth) health = maxHealth;
    else if (health >= 0) health = health;
    else this->warning("health < 0");
}

void Monster::setMaxHealth(float maxHealth)
{
    this->maxHealth = maxHealth;
}

void Monster::setDamage(float damage)
{
    this->damage = damage;
}

string Monster::getName()
{
    return this->name;
}

float Monster::getHealth() const
{
    return this->health;
}

float Monster::getMaxHealth()
{
    return this->maxHealth;
}

float Monster::getDamage()
{
    return this->damage;
}

Monster::~Monster()
{
    cout << "Объект " << name << " уничтожается!" << endl;
}

void Monster::warning(string msg)
{
    cout << "Warning: " << msg << endl;
}

#pragma once
#include <iostream>
using namespace std;

class Monster
{
private:
    std::string name;
    float health;
    float maxHealth;
    float damage;

public:
    Monster(std::string name, float health, float maxHealth, float damage);
    Monster();

    float getLevel();
    void applyDamage(float damage);
    void applyDamage();
    void recovery();
    void attack(Monster& m);
    void setName(string name);
    void setHealth(float health);
    void setMaxHealth(float maxHealth);
    void setDamage(float damage);
    string getName();
    float getHealth();
    float getMaxHealth();
    float getDamage();

    ~Monster();
protected:
    void warning(string msg);
};


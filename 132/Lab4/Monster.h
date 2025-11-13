#pragma once
#include <iostream>
using std::string;

class Monster
{
public:
    string name;
    float health;
    float damage;
    float maxHealth;
    Monster(string name, float health, float maxHealth, float damage);
    Monster();
    ~Monster();
    float getLevel();
    void applyDamage(float damage);
    void applyDamage();
    void recovery();
    void attack(Monster& m);
};


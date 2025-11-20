#pragma once
#include <iostream>
using std::string;

class Monster
{
    friend class AIMonster;
protected:
    void printWarning(string msg);
private:
    string name;
    float health;
    float damage;
    float maxHealth;
public:
    int static counter;
    Monster(string name, float health, float maxHealth, float damage);
    Monster();
    ~Monster();
    void static resetCounter();
    string getName();
    float getHealth();
    float getDamage();
    float getMaxHealth();
    void setHealth(float health);

    float getLevel();
    void applyDamage(float damage);
    void applyDamage();
    void recovery();
    void attack(Monster& m);
    friend void test(const Monster& m);
};


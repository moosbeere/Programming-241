#pragma once
#include <iostream>
using std::string;

class Monster
{
    friend class AIMonster;
protected:
    void printWarning(string msg);
    string name;
    void setHealth(float health);

private:
    
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

    float getLevel();
    void applyDamage(float damage);
    void applyDamage();
    void recovery();
    void attack(Monster& m);
    friend void test(const Monster& m);
};


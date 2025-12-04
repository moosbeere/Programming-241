#pragma once
#include <iostream>
using namespace std;

class Monster
{
    friend void test(const Monster& m);
    friend class AIMonster;
private:
    std::string name;
    float health;
    float maxHealth;
    float damage;

public:
    Monster(std::string name, float health, float maxHealth, float damage);
    Monster();

    static int counter;
    static void resetCounter();
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
    float getHealth() const;
    float getMaxHealth();
    float getDamage();

    ~Monster();
protected:
    void warning(string msg);
};


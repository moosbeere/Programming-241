#pragma once
#include <iostream>
using namespace std;

class Monster
{
    friend class AIMonster;
protected:
    void printWarning(string msg);
    string name;
    void setHealth(double health);

private:
    
    double health;
    float damage;
    float maxHealth;
public:
    int static counter;
    Monster(string name, double health, float maxHealth, float damage);
    Monster();
    ~Monster();
    void static resetCounter();
    string getName();
    double getHealth();
    float getDamage();
    float getMaxHealth();

    float getLevel();
    void applyDamage(float damage);
    void applyDamage();
    void recovery();
    virtual void attack(Monster& m) = 0;
    //virtual void print() final; ключевое слово final указывает на невозможность переопределения функции в дочерних классах
    virtual void print() ;
    explicit operator string() const;
    friend void test(const Monster& m);
};


#pragma once

#include <iostream>


using namespace std;


class Weapon
{
private:
    string name;
    float damage;
    float weight;
public:
    Weapon(string inputName, float inputDamage, float inputWeight);
    Weapon();

    ~Weapon();

    // get методы
    string getName();
    float getDamage();
    float getWeight();

    // set метод для урона
    void setDamage(float newDamage);

    void printInfo();

    bool checkWeight(float maxWeight);

    int newWeapon(Weapon& newItem);

    int newWeapon(int newWeight);
    friend class Characteristic;
};
class Characteristic
{
private:
    float strength;

public:
    Characteristic(float inputStrength);

    float GetDamage(const Weapon& weapon);
};
class MyMath
{
private:
    static int staticMethodCount;
public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static int Div(int a, int b);
    static int getStaticCount();
};
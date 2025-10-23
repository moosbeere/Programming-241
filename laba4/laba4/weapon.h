#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace ::std;



class weapon
{
private:
    string name;
    int weight;
    int damage;

public:
    weapon(string Wname, int Wweight, int Wdamage);
    weapon();
    ~weapon();

    string getName() const;
    void print();

    int weight_possible() const;
    int getweight() const;
    int getdamage() const;  
    void setdamage(int newdamage);  

    int suma_weight(const weapon& oweapon) const;
    int suma_weight2(int oweight) const;
    int suma_weight3(const weapon& oweapon) const;

    friend class Characteristic;
};


class Characteristic
{
private:
    int strength; 

public:
    Characteristic(int str);
    int getStrength() const;
    int GetDamage(const weapon& w) const;
};

class MyMath
{
private:
    static int count; 

public:
  
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static double Div(int a, int b);

   
    static int getcount();
};

#endif
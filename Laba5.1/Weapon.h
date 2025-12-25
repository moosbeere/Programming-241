#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

using namespace std;

// 1. Перечисление типов оружия
enum WeaponType {
    ONEHANDED,   
    TWOHANDED,   
    BOW,         
    CROSSBOW     
};

class Characteristic;  


class Weapon {
protected:
    string name;
    int damage;
    float weight;
    WeaponType type;  

public:
    
    Weapon(string name, int damage, float weight, WeaponType type);
    Weapon();
    Weapon(string name, int damage, float weight); 
    virtual ~Weapon();

    
    bool canLift(float maxWeight) const;
    float getTotalWeight(const Weapon& otherWeapon) const;
    float getTotalWeight(float otherWeight) const;

    
    string getName() const { return name; }
    virtual int getDamage() const { return damage; }  // 12. Виртуальный метод
    float getWeight() const { return weight; }
    WeaponType getType() const { return type; }  // 2. GET-метод для типа

    // SET-метод
    void setDamage(int newDamage) { damage = newDamage; }

    virtual bool operator>(const Weapon& other) const;
    virtual bool operator<(const Weapon& other) const;

    
    friend class Characteristic;
};

// 7. Дочерний класс магического оружия
class MagicWeapon : public Weapon {
private:
    int extraDamage;  // 8. Дополнительный магический урон

public:
    
    MagicWeapon(string name, int damage, float weight, WeaponType type, int extraDamage);
    MagicWeapon();

    int getExtraDamage() const { return extraDamage; }

    // 13. Переопределение виртуального метода
    int getDamage() const override;
};

#endif
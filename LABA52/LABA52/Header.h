#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class weapon {
protected:
    string name;
    int weight;
    int damage;
    WeaponType type;

public:
    weapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype = ONEHANDED);
    weapon();
    virtual ~weapon();

    string getName() const;
    WeaponType getType() const;
    void print() const;
    int weight_possible() const;
    int getweight() const;
    virtual int getdamage() const;
    void setdamage(int newdamage);
    void setType(WeaponType newType);
    int suma_weight(const weapon& oweapon) const;
    int suma_weight2(int oweight) const;
    int suma_weight3(const weapon& oweapon) const;
    bool operator>(const weapon& other) const;
    bool operator<(const weapon& other) const;

    virtual void Attack() = 0;
};

struct Player {
    int id;
    string login;
    string password;
    void printPlayer() const;
};

class MagicWeapon : public weapon {
private:
    int additionalDamage;

public:
    MagicWeapon(string Wname, int Wweight, int Wdamage, int addDamage, WeaponType Wtype = ONEHANDED);
    MagicWeapon();
    int getAdditionalDamage() const;
    virtual int getdamage() const override;
    virtual void Attack() override;
};

class DisposableWeapon : public weapon {
private:
    bool used;

public:
    DisposableWeapon(string Wname, int Wweight, int Wdamage, WeaponType Wtype = ONEHANDED);
    DisposableWeapon();
    virtual int getdamage() const override;
    virtual void Attack() override;
    bool isUsed() const;
    void reset();
};

class Characteristic {
private:
    int strength;

public:
    Characteristic(int str);
    int getStrength() const;
    int GetDamage(const weapon& w) const;
};

template<typename TLeft, typename TRight>
class DualWield {
private:
    TLeft leftHand;
    TRight rightHand;

public:
    DualWield(const TLeft& left, const TRight& right);

    TLeft getLeftHand() const;
    void setLeftHand(const TLeft& left);

    TRight getRightHand() const;
    void setRightHand(const TRight& right);
};

string getWeaponTypeName(WeaponType type);

#endif

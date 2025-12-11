#pragma once
class Weapon;

class Characteristic {
private:
    int strength;

public:
    Characteristic(int s);

    int GetDamage(const Weapon& w);
};

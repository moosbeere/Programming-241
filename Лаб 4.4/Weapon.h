#pragma once
#include <string>
using namespace std;

class Characteristic;

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    Weapon(string n, int d, int w);
    ~Weapon();

    bool canLift(int maxWeight);
    float totalWeight(float w);
    float totalWeight(const Weapon& other);

    string getName() const;
    int getDamage() const;
    float getWeight() const;

    void setDamage(int d);

    friend class Characteristic;
};
#pragma once

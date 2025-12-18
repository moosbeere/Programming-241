#pragma once
#include <string>
using namespace std;

class Weapon {
public:
    string name;
    int damage;
    float weight;

    Weapon(string n, int d, int w);
    ~Weapon();

    bool canLift(int maxWeight);
    float totalWeight(float w);
    float totalWeight(const Weapon& x);
};
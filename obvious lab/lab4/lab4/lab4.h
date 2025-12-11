#pragma once
#include <string>

class Characteristic;

class orujie {
private:
    float damage;
    std::string name;
    float weight;
    int allowed_weight;

public:
    orujie(float d, std::string n, float w);
    orujie();
    ~orujie();

    // 4.2
    float getDamage() const;
    std::string getName() const;
    float getWeight() const;
    int getAllowedWeight() const;

    // 4.3
    void setDamage(float newDamage);

    bool checkWeight(int maxWeight);
    float sumWeight(const orujie& other);
    float sumWeight(float otherWeight);
    float sumWeightWithOverload(const orujie& other);

    void printInfo() const;

    // 4.6
    friend class Characteristic;
};

// 4.5
class Characteristic {
private:
    float strength;

public:
    Characteristic(float str);
    float GetDamage(const orujie& weapon) const;
    float getStrength() const;
};

// 4.9
class MyMath {
private:
    static int methodCallCount; // 4.10

public:
    static float Add(float a, float b);
    static float Sub(float a, float b);
    static float Mult(float a, float b);
    static float Div(float a, float b);

    static int getMethodCallCount();
};

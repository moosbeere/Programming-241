#include "lab4.h"
#include <iostream>

orujie::orujie(float d, std::string n, float w) {
    damage = d;
    name = n;
    weight = w;
    allowed_weight = 50;
}

orujie::orujie() : orujie(10, "wrist", 1) {}

orujie::~orujie() {
    std::cout << name << " (damage: " << damage<< ", weight: " << weight<< ") уничтожается;" << std::endl;
}

// 4.2
float orujie::getDamage() const { return damage; }
std::string orujie::getName() const { return name; }
float orujie::getWeight() const { return weight; }
int orujie::getAllowedWeight() const { return allowed_weight; }

// 4.3
void orujie::setDamage(float newDamage) {
    if (newDamage >= 0) {
        damage = newDamage;
    }
    else {
        std::cout << "Ошибка: урон не может быть отрицательным!" << std::endl;
    }
}

bool orujie::checkWeight(int maxWeight) {
    return weight <= maxWeight;
}

float orujie::sumWeight(const orujie& other) {
    return weight + other.weight;
}

float orujie::sumWeight(float otherWeight) {
    return weight + otherWeight;
}

float orujie::sumWeightWithOverload(const orujie& other) {
    return sumWeight(other.weight);
}

void orujie::printInfo() const {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Урон: " << damage << std::endl;
    std::cout << "Вес: " << weight << std::endl;
    std::cout << std::endl;
}

// 4.5
Characteristic::Characteristic(float str) : strength(str) {}

// 4.7
float Characteristic::GetDamage(const orujie& weapon) const {
    return strength + weapon.damage;
}

float Characteristic::getStrength() const {
    return strength;
}

// 4.10
int MyMath::methodCallCount = 0;

// 4.9 и 4.11
float MyMath::Add(float a, float b) {
    methodCallCount++;
    return a + b;
}

float MyMath::Sub(float a, float b) {
    methodCallCount++;
    return a - b;
}

float MyMath::Mult(float a, float b) {
    methodCallCount++;
    return a * b;
}

float MyMath::Div(float a, float b) {
    methodCallCount++;
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
}

int MyMath::getMethodCallCount() {
    return methodCallCount;
}
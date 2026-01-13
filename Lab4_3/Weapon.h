#pragma once
#ifndef Header_H
#define Header_H

#include <string>

using namespace std;

class Header {
public:
    string name;
    int damage;
    float weight;

    Header(string n, int d, float w); // конструктор с параметрами
    Header();                         // конструктор без параметров
    ~Header();                        // деструктор

    void print();
    bool isTooHeavy(float maxWeight);
    float totalWeight(float w);
    float totalWeight(Header other);
};

#endif


#pragma once
#include <string>
using namespace std;
class Vehicle {
protected:
    string name;
    int maxSpeed;

public:
    Vehicle(string n, int speed);
    virtual ~Vehicle();

    virtual void printInfo() const;
};


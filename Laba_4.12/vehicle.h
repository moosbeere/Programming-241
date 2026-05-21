#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    string name;
    double maxSpeed;
    double currentSpeed;
    double position;

public:
    Vehicle(string n, double maxS);
    virtual ~Vehicle();

    virtual void updateSpeed(double roadLimit) = 0;
    void move(double timeStep);

    string getName() const;
    double getPosition() const;
    double getCurrentSpeed() const;
};

class Car : public Vehicle {
public:
    Car(string n, double maxS);
    void updateSpeed(double roadLimit) override;
};

class Truck : public Vehicle {
public:
    Truck(string n, double maxS);
    void updateSpeed(double roadLimit) override;
};

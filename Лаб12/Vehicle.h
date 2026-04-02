#pragma once
#include <string>

using namespace std;

class Vehicle {
protected:
    double position = 0.0;
    double speed;
    double maxSpeed;
    double brakeStep;

public:
    Vehicle(double maxSp, double brake);
    virtual string getType() const = 0;

    double getPosition() const;

    void simulate(double dt, double speedLimit);
};
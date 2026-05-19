#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
protected:
    std::string name;
    double maxSpeed;
    double currentSpeed;
    double position;

public:
    Vehicle(std::string n, double maxSpd);

    virtual ~Vehicle();

    virtual void accelerate(double value);

    double getMaxSpeed() const;
    double getCurrentSpeed() const;
    double getPosition() const;

    void move(double time);

    virtual void info() const;
};

#endif
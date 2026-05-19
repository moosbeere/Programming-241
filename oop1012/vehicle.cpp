#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(std::string n, double maxSpd)
{
    name = n;
    maxSpeed = maxSpd;
    currentSpeed = 0;
    position = 0;
}

Vehicle::~Vehicle() {}

void Vehicle::accelerate(double value)
{
    currentSpeed += value;

    if (currentSpeed > maxSpeed)
    {
        currentSpeed = maxSpeed;
    }
}

double Vehicle::getMaxSpeed() const
{
    return maxSpeed;
}

double Vehicle::getCurrentSpeed() const
{
    return currentSpeed;
}

double Vehicle::getPosition() const
{
    return position;
}

void Vehicle::move(double time)
{
    position += currentSpeed * time;
}

void Vehicle::info() const
{
    std::cout << name
        << " | скорость: "
        << currentSpeed
        << " | позиция: "
        << position
        << std::endl;
}
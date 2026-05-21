#include "TransportUnit.h"

// Реализация класса Car
double Car::calculateToll(double distance) const
{
    return distance * 0.1;
}

// Реализация класса Truck
double Truck::calculateToll(double distance) const
{
    return distance * 0.3 + 5.0;
}
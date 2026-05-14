#include <iostream>
#include "Truck.h"

Truck::Truck(std::string name, int maxSpeed)
    : Vehicle(name, maxSpeed)
{
}

void Truck::info() const {
    std::cout << "Truck: "
        << name
        << ", max speed: "
        << maxSpeed
        << std::endl;
}
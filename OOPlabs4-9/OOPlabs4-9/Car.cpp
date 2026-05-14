#include <iostream>
#include "Car.h"

Car::Car(std::string name, int maxSpeed)
    : Vehicle(name, maxSpeed)
{
}

void Car::info() const {
    std::cout << "Car: "
        << name
        << ", max speed: "
        << maxSpeed
        << std::endl;
}
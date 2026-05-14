#include <iostream>
#include "Car.h"

Car::Car(std::string name, int maxSpeed)
    : TransportUnit(name, maxSpeed)
{
}

double Car::calculateToll(double distance) const {
    return distance * 0.1;
}

void Car::info() const {
    std::cout << "Car: " << name << " | " << maxSpeed << std::endl;
}#pragma once

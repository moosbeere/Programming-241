#include "Car.h"
#include <iostream>

Car::Car(std::string brand):brand(brand) {};

double Car::calculateToll(double distance) const
{
    return distance * 0.1;
}

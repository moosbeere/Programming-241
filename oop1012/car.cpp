#include "car.h"

Car::Car(std::string n,
    double maxSpd)
    : Vehicle(n, maxSpd)
{
}

void Car::accelerate(double value)
{
    // легковая машина ускоряется быстрее
    Vehicle::accelerate(value * 1.5);
}
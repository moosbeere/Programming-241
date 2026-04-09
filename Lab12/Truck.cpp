#include "Truck.h"
#include <iostream>

Truck::Truck(std::string brand, int maxSpeed)
    : Vehicle(brand, maxSpeed, 4.0, 7.0)   // очень медленное ускорение/торможение
{
}

void Truck::getStatus() const {
    Vehicle::getStatus();
    std::cout << "Тип: тяжёлый грузовик (Truck)\n";
}
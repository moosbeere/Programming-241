#include "Car.h"
#include <iostream>

Car::Car(std::string brand, int maxSpeed)
    : Vehicle(brand, maxSpeed, 20.0, 25.0)
{
}

void Car::getStatus() const {
    Vehicle::getStatus();
    std::cout << "Тип: легковой автомобиль\n";
}
#include "vehicle.h"

double Car::calculateToll(double distance) const 
{
    return distance * 0.1;
}

void Car::printInfo() const 
{
    std::cout << "Легковой автомобиль (0.1 у.е./км)";
}

double Truck::calculateToll(double distance) const 
{
    return distance * 0.3 + 5.0;
}

void Truck::printInfo() const 
{
    std::cout << "Грузовик (0.3 у.е./км + 5.0 у.е.)";
}
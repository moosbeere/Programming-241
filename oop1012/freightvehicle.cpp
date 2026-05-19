#include "freightvehicle.h"

FreightVehicle::FreightVehicle(std::string n,
    double maxSpd,
    double cargo)
    : Vehicle(n, maxSpd)
{
    cargoCapacity = cargo;
}

double FreightVehicle::getCargoCapacity() const
{
    return cargoCapacity;
}
#pragma once
#ifndef FREIGHTVEHICLE_H
#define FREIGHTVEHICLE_H

#include "vehicle.h"

class FreightVehicle : public Vehicle
{
private:
    double cargoCapacity;

public:
    FreightVehicle(std::string n,
        double maxSpd,
        double cargo);

    double getCargoCapacity() const;
};

#endif
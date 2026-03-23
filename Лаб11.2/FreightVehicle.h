#pragma once

#include "Vehicle.h"

class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;

public:
    FreightVehicle(double c);

    double getCargoCapacity() const;
};
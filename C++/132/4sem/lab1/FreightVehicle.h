#pragma once
#include "Vehicle.h"
class FreightVehicle :
    public Vehicle
{
private:
    int cargoCapacity;

public:
    FreightVehicle(string brand, int maxSpeed, int cargoCapacity);
    void getStatus() override;
};


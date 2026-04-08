#pragma once
#include "Vehicle.h"
class FreightVehicle :
    public Vehicle
{
private:
    float cargoCapacity;
public:
    FreightVehicle(string b, float m, float c);

    void getStatus();
};


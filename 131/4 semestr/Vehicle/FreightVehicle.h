#pragma once
#include "Vehicle.h"
#include <string>
class FreightVehicle :
    public Vehicle
{
private:
    int cargoCapacity;
public:
    FreightVehicle(string brand, int maxSpeed, int cargoCapacity);
    void getStatus() override;
	int getCargoCapacity();
};


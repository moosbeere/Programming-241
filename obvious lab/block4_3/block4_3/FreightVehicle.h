#pragma once
#include "Vehicle.h"
#include <string>

class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;
public:
    FreightVehicle(string brand, int maxSpeed, double cargoCap);
    void getStatus();
    double getCargoCapacity() const override;
};
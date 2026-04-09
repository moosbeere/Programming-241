#pragma once
#include "Vehicle.h"

using namespace std;

class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;
public:
    FreightVehicle(string brand, int maxSpeed, double cargoCap);
    void getStatus() const override;
    double getCargoCapacity() const override { return cargoCapacity; }
};
#include "FreightVehicle.h"
#include <iostream>

FreightVehicle::FreightVehicle(string brand, int maxSpeed, double cargoCap)
    : Vehicle(brand, maxSpeed)
{
    cargoCapacity = cargoCap;
}

void FreightVehicle::getStatus() {
    Vehicle::getStatus();
    cout << "Грузоподъемность: " << cargoCapacity << " тонн" << "\n" << endl;
}
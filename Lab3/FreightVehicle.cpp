#include "FreightVehicle.h"
#include <iostream>

// Конструктор FreightVehicle
FreightVehicle::FreightVehicle(string brand, int maxSpeed, double cargoCap)
    : Vehicle(brand, maxSpeed)
{
    cargoCapacity = cargoCap;
}

void FreightVehicle::getStatus() {
    // вызываем родительский метод
    Vehicle::getStatus();

    cout << "Грузоподъемность: " << cargoCapacity << " тонн" << "\n" << endl;
}
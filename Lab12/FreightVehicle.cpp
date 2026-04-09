#include "FreightVehicle.h"
#include <iostream>

using namespace std;

FreightVehicle::FreightVehicle(string brand, int maxSpeed, double cargoCap)
    : Vehicle(brand, maxSpeed, 5.0, 8.0),
    cargoCapacity(cargoCap) {
}

void FreightVehicle::getStatus() const {
    Vehicle::getStatus();
    cout << "Тип: грузовой автомобиль\n"
        << "Грузоподъёмность: " << cargoCapacity << " тонн\n";
}
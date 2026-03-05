#include "FreightVehicle.h"
#include <iostream>
using namespace std;

FreightVehicle::FreightVehicle(string brand, int maxSpeed, int currentSpeed, double cargoCapacity)
	:Vehicle(brand, maxSpeed, currentSpeed) {
	this->cargoCapacity = cargoCapacity;
}

void FreightVehicle::getStatus()
{
	Vehicle::getStatus();
	cout << "Грузоподъёмность: " << cargoCapacity << " тонн\n\n";
}

double FreightVehicle::getCargoCapacity()
{
	return cargoCapacity;
}


#include "FreightVehicle.h"

FreightVehicle::FreightVehicle(string b, float m, float c) : Vehicle(b, m), cargoCapacity(c) {}

void FreightVehicle::getStatus()
{
	Vehicle::getStatus();

	cout << "Грузоподъемность: " << cargoCapacity << endl;
}

#include "Vehicle.h"

Vehicle::Vehicle(string b) : brand(b) {
	DispatchCenter::totalVehiclesDispatched++;
	cout << "Создано ТС: " << brand << endl;
};
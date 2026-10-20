#include "Vehicle.h"
#include "DispatchCenter.h"
#include <iostream>


Vehicle::Vehicle(string brand, int maxSpeed) :brand(brand), maxSpeed(maxSpeed) {
	currentSpeed = 0;
	//lab6
	DispatchCenter::totalVehiclesDispatched++;
}

void Vehicle::accelerate(int increment)
{
	currentSpeed += increment;
	if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
}

void Vehicle::brake(int decrement)
{
	currentSpeed -= decrement;
	if (currentSpeed < 0) currentSpeed = 0;
}

void Vehicle::getStatus()
{
	cout << "Brand: " << brand << " MaxSpeed: " << maxSpeed << " CurrentSpeed: " << currentSpeed << endl;
};

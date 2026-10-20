#include "Vehicle.h"
#include <iostream>
#include "DispatchCenter.h"

Vehicle::Vehicle(string brand, int maxSpeed):brand(brand), maxSpeed(maxSpeed)
{
	currentSpeed = 0;
	DispatchCenter::totalVehiclesDispatched++;
}

void Vehicle::accelerate(int increment)
{
	if ((currentSpeed + increment) > maxSpeed) currentSpeed = maxSpeed;
	else currentSpeed += increment; // currentSpeed = currentSpeed + increment
}

void Vehicle::brake(int decrement)
{
	if ((currentSpeed - decrement) <= 0) currentSpeed = 0;
	else currentSpeed -= decrement;
}

void Vehicle::getStatus()
{
	cout << "Brand: " << brand << endl
		<< "Current speed: " << currentSpeed << endl
		<< "Max speed: " << maxSpeed << endl;
}

string Vehicle::getBrand()
{
	return brand;
}

bool Vehicle::operator<(Vehicle& other)
{
	return maxSpeed < other.maxSpeed;
}





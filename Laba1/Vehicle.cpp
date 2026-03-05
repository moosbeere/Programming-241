#include <iostream>
#include "Vehicle.h"
Vehicle::Vehicle(string brand, int maxSpeed, int currentSpeed) : brand(brand), maxSpeed(maxSpeed), currentSpeed(currentSpeed) {}

Vehicle::Vehicle(): brand("Unk"), maxSpeed(0), currentSpeed(0){}


void Vehicle::accelerate(int increment)
{
	if ((currentSpeed + increment) > maxSpeed)
		currentSpeed = maxSpeed;
	else
		currentSpeed += increment;
}

void Vehicle::brake(int decrement)
{
	if ((currentSpeed - decrement) <= 0)
		currentSpeed = 0;
	else
		currentSpeed -= decrement;
}

void Vehicle::getStatus()
{
	cout << "Brand: " << brand << "\nCurrentSpeed: " << currentSpeed << "\nMaxSpeed:" << maxSpeed <<endl;
}

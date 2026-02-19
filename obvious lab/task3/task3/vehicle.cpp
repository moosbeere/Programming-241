#include <iostream>
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(string brand, int maxSpeed) :brand(brand), maxSpeed(maxSpeed), currentSpeed(0)
{

}

void Vehicle::accelerate(int increment)
{
	if (increment + increment > maxSpeed) {
		currentSpeed = maxSpeed;
	}
	else {
		currentSpeed += increment;
	}
}

void Vehicle::brake(int decrement)	
{
	if (currentSpeed + decrement <= 0) {
		currentSpeed = 0;
	}
	else {
		currentSpeed -= decrement;
	}
}

void Vehicle::getStatus() const
{
	cout << "машина: " << brand << endl;
	cout << "Макс скорость: " << maxSpeed << endl;
	cout << "текущая скорость: " << currentSpeed << endl;

}


FreightVehicle::FreightVehicle(string brand, int maxSpeed, float capacity)
	: Vehicle(brand, maxSpeed), cargoCapacity(capacity) {
}





void FreightVehicle::getStatus() {
	Vehicle::getStatus();
	cout << "Грузоподъемность: " << cargoCapacity << " tonn" << endl;
}
float FreightVehicle::getCargoCapacity(){
	return cargoCapacity;
}




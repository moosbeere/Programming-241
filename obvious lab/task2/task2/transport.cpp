#include <iostream>
#include "transport.h"
using namespace std;

Vehicle::Vehicle(const string brand, int maxSpeed) :brand(brand), maxSpeed(maxSpeed), currentSpeed(0)
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
	cout << "ћакс скорость: " << maxSpeed << endl;
	cout << "текуща€ скорость: " << currentSpeed << endl;
}
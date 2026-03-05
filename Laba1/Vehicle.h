#pragma once
#include <string>
using namespace std;

class Vehicle 
{
protected:
	string brand;
	int maxSpeed;
	int currentSpeed;


public:
	Vehicle(string brand, int maxSpeed, int currentSpeed);
	Vehicle();


	void accelerate(int increment);
	void brake(int decrement);
	void getStatus();
};

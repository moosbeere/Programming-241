#pragma once
#include <string>
using namespace std;

class Vehicle
{
private:
	string brand;
	int maxSpeed;
	int currentSpeed;

public:
	Vehicle(string brand, int maxSpeed);
	void accelerate(int increment);
	void brake(int decrement);
	virtual void getStatus();
};


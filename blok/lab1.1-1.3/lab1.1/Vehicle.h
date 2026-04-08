#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
private:
	string brand; // марка
	float maxSpeed; // максимальная скорость
	float currentSpeed = 0; // текущая скорость
public:

	Vehicle(string b, float m);

	void accelerate(int increment);
	void brake(int decrement);
	void getStatus();
};


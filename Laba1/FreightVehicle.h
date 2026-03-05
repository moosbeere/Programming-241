#pragma once
#include"Vehicle.h"
#include<iostream>
using namespace std;

class FreightVehicle : public Vehicle 
{
private:
	double cargoCapacity;

public:
	FreightVehicle(string brand, int maxSpeed, int currentSpeed, double cargoCapacity);

	void getStatus();

	double getCargoCapacity();
};
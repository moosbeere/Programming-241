#pragma once
#include <iostream>
#include <string>
#include "PublicTransport.h"
#include "vehicle.h"
using namespace std;
class Bus:PublicTransport
{
private:
	string fuelType;
public:
	Bus(const string& brand, int maxSpeed, const string& route, int capacity, const string& fuel);

	string getFueltypel() const;

	void displayInfo() const override;
	string getType() const override;
};


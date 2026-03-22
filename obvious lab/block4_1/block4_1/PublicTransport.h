#pragma once
#include <iostream>;
#include <string>
#include "Vehicle.h"
using namespace std;
class PublicTransport:virtual public Vehicle
{
public:
	string routeNumber;
	int passengerCapacity;

	PublicTransport(const string& brand, int maxSpeed, const string& route, int capacity);

	void getInfo();
};


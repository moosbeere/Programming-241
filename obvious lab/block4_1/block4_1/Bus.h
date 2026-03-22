#pragma once
#include <iostream>
#include "PublicTransport.h"
#include <string>
using namespace std;

class Bus:  PublicTransport, virtual public Vehicle
{
public:
	string fuelType;

	Bus(const string& brand, int maxSpeed, const string& route, int capacity, const string& fuel);
	void getInfo();
};


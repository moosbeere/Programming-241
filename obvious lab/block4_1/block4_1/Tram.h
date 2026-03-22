#pragma once
#include <iostream>
#include "PublicTransport.h"
using namespace std;
class Tram:PublicTransport, virtual public Vehicle
{
public:
	int electricLineVoltage;

 
	Tram(const string& brand, int maxSpeed, const string& route, int capacity, int voltage);

	void getInfo();
};


#include "Bus.h"
#include <iostream>

using namespace std;



Bus::Bus(const string& brand, int maxSpeed, const string& route, int capacity, const string& fuel):
	PublicTransport(brand, maxSpeed, route, capacity), Vehicle(brand, maxSpeed), fuelType(fuel)
{

}

void Bus::getInfo()
{
	PublicTransport::getInfo();
	cout << "Топливо: " << fuelType << "\n";
}

	
#include "Bus.h"
#include <iostream>
#include <string>
using namespace std;


Bus::Bus(const string& brand, int maxSpeed, const string& route, int capacity, const string& fuel)
	:Vehicle(brand, maxSpeed),PublicTransport(brand, maxSpeed, route, capacity), fuelType(fuel)
{

}

string Bus::getFueltypel() const
{
	return fuelType;
}





string Bus::getType() const
{
	return "автобус";
}

void Bus::displayInfo()const
{
	cout << "Автобус" << endl;
	getStatus();

	cout << "Маршрут: " << routeNumber << endl;
	cout << "Вместимость: " << passengerCapacity << endl;
	cout << "Вид топлива: " << fuelType << endl;
}

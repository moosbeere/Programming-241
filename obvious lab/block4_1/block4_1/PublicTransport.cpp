#include "PublicTransport.h"
#include <iostream>

using namespace std;

PublicTransport::PublicTransport(const string& brand, int maxSpeed, const string& route, int capacity):Vehicle(brand, maxSpeed), routeNumber(route), passengerCapacity(capacity)
{
}

void PublicTransport::getInfo()
{
	cout << "Путь: " << routeNumber <<"\n" "Вместимость: " << passengerCapacity << "\n";
}

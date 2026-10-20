#include "Bus.h"

Bus::Bus(string brand, int maxSpeed, int routeNumber, int passengerCapacity, string fuelType) : Vehicle(brand, maxSpeed), PublicTransport(routeNumber, passengerCapacity)
{
	fuelType = fuelType;	
}

void Bus::getStatus()
{
	Vehicle::getStatus();
	cout << "routeNumber: " << routeNumber << endl
		<< "passengerCapacity: " << passengerCapacity << endl
		<< "Fuel type: " << fuelType << endl;
}

Tram::Tram(string brand, int maxSpeed, int routeNumber, int passengerCapacity, double electricLineVoltage) : Vehicle(brand, maxSpeed), PublicTransport(routeNumber, passengerCapacity)
{
	electricLineVoltage = electricLineVoltage;
}

void Tram::getStatus()
{
	Vehicle::getStatus();
	cout << "routeNumber: " << routeNumber << endl
		<< "passengerCapacity: " << passengerCapacity << endl
		<< "electricLineVoltage: " << electricLineVoltage << endl;
}

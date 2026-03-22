#include "Tram.h"

Tram::Tram(const string& brand, int maxSpeed, const string& route, int capacity, int voltage):PublicTransport(brand, maxSpeed, route, capacity),
Vehicle(brand, maxSpeed), electricLineVoltage(voltage)
{
}

void Tram::getInfo()
{
	PublicTransport::getInfo();
	cout << "Напряжение: " << electricLineVoltage << "V" "\n";
}


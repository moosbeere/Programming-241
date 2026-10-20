#pragma once
#include "PublicTransport.h"
#include "Vehicle.h"
class Bus :
    public PublicTransport, public Vehicle
{
    string fuelType;
public:
    Bus(string brand, int maxSpeed, int routeNumber, int passengerCapacity, string fuelType);
	void getStatus() override;
};

class Tram :
    public PublicTransport, Vehicle 
{
    double electricLineVoltage;
public:
    Tram(string brand, int maxSpeed, int routeNumber, int passengerCapacity, double electricLineVoltage);
	void getStatus() override;
};
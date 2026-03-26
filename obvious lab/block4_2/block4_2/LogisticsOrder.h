#pragma once
#include "Vehicle.h"

class LogisticsOrder {
private:
	double weight;
public:
	LogisticsOrder(double w);
	void assignVehicle(Vehicle v);
	double getWeight();
};
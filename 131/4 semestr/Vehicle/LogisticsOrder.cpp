#pragma once
#include "Vehicle.h"
#include "FreightVehicle.h"

class LogisticsOrder
{
private:
	int weight;
public:
	void AssignedVehicle(FreightVehicle& v) {
		if(weight > v.getCargoCapacity()) {
			// Assign vehicle to order
			throw std::invalid_argument("Vehicle cannot be assigned to order: weight exceeds cargo capacity.");
		}
		if(weight <= 0) {
			throw std::invalid_argument("Weight must be greater than zero.");
		}	
	}
};
#include <iostream>
#include "Vehicle.h"
#include "DispatchCenter.h"

Vehicle::Vehicle(std::string name, int maxSpeed)
    : name(name), maxSpeed(maxSpeed)
{
    DispatchCenter::totalVehiclesDispatched++;
}

Vehicle::~Vehicle() {}

void Vehicle::info() const {
    std::cout << "Vehicle: "
        << name
        << ", max speed: "
        << maxSpeed
        << std::endl;
}

int Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

bool Vehicle::operator<(const Vehicle& other) const {
    return maxSpeed < other.maxSpeed;
}
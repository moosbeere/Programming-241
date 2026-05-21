#include "Vehicle.h"

Vehicle::Vehicle(int speed) : maxSpeed(speed) {}

bool Vehicle::operator<(const Vehicle& other) const {
    return maxSpeed < other.maxSpeed;
}

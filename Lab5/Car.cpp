#include "Car.h"

Car::Car(const std::string& b) : brand(b) {}

double Car::calculateToll(double distance) const {
    return distance * 0.1;
}

std::string Car::getDescription() const {
    return brand;
}
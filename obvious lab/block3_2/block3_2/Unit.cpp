#include "Unit.h"
#include <string>
using namespace std;
TransportUnit::TransportUnit(string plate) : licensePlate(plate) {}

Car::Car(string plate) : TransportUnit(plate) {}

double Car::calculateToll(double distance) const {
    return distance * 0.1;
}

std::string Car::getType() const {
    return "Автомобиль " + licensePlate;
}

Truck::Truck(double cap, string plate)
    : TransportUnit(plate), capacity(cap) {
}

double Truck::calculateToll(double distance) const {
    double extra = (capacity > 15) ? 10.0 : 0.0;
    return distance * 0.3 + 5.0 + extra;
}

std::string Truck::getType() const {
    return "Грузовик " + licensePlate + " (" + std::to_string(capacity) + "т)";
}
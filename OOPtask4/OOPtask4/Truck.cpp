#include "Truck.h"

double Truck::calculateToll(double distance) const {
    return distance * 0.3 + 5.0;
}
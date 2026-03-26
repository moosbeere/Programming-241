#include "Truck.h"


double Truck::calculateToll(double distance) const {
    // Плата: 0.3 у.е. за километр + фиксированный сбор 5 у.е.
    return distance * 0.3 + 5.0;
}

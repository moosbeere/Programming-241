#include "TransportUnit.h"
#include <string>

double Bus::calculateToll(double distance) const {
    // Условная стоимость: 10 руб/км
    return distance * 10.0;
}

std::string Bus::getName() const {
    return "Автобус";
}

#include "Truck.h"

Truck::Truck(): Vehicle(25, 0.8) {}

string Truck::getType() const {
    return "Тягач";
}
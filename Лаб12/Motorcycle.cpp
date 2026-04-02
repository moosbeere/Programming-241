#include "Motorcycle.h"

Motorcycle::Motorcycle(): Vehicle(55, 1.8) {}

string Motorcycle::getType() const {
    return "Мотоцикл";
}
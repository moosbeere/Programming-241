#include "Car.h"

// Реализация метода calculateToll для Car
double Car::calculateToll(double distance) const {
    // Плата: 0.1 у.е. за километр
    return distance * 0.1;
}

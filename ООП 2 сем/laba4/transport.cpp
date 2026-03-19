#include "transport.h"  

// Реализация метода calculateToll для класса Car
double Car::calculateToll(double distance) const {
    // Плата за проезд: 0.1 у.е. за каждый километр
    return distance * 0.1;
}

// Реализация метода calculateToll для класса Truck
double Truck::calculateToll(double distance) const {
    // Плата за проезд грузовика: 0.3 у.е. за километр плюс фиксированный сбор 5 у.е.
    return distance * 0.3 + 5.0;
}

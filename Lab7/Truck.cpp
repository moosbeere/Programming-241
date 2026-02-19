#include "Truck.h"

double Truck::calculateToll(double distance) const {
    // Пример тарифа для грузовика
    return distance * 20.0;
}

std::string Truck::getDescription() const {
    return "Грузовой автомобиль";
}
#include "Car.h"

double Car::calculateToll(double distance) const {
    // Пример тарифа для легкового автомобиля
    return distance * 10.0;
}

std::string Car::getDescription() const {
    return "Легковой автомобиль";
}
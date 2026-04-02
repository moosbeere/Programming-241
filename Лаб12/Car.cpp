#include "Car.h"

Car::Car(): Vehicle(50, 2) {}

string Car::getType() const {
    return "Автомобиль";
}
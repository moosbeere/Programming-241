#include "vehicle.h"

double Car::calculateToll(double distance) const {
    return distance * 0.1;
}

void Car::printInfo() const {
    cout << "Легковой автомобиль";
}

double Truck::calculateToll(double distance) const {
    return distance * 0.3 + 5.0;
}

void Truck::printInfo() const {
    cout << "Грузовик";
}

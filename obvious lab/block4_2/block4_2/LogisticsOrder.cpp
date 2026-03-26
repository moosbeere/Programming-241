#include "LogisticsOrder.h"
#include "FreightVehicle.h"
#include <iostream>

LogisticsOrder::LogisticsOrder(double w) : weight(w) {}

void LogisticsOrder::assignVehicle(Vehicle v) {
    if (weight < 0) {
        throw invalid_argument("Масса не может быть отрецательной");
    }
    if (weight > v.getCargoCapacity()) {
        throw invalid_argument("Не допускаеться такая масса");
    }
    cout <<"" << std::endl;
}

double LogisticsOrder::getWeight() {
    return weight;
}
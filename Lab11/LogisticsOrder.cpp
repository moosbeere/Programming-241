#include "LogisticsOrder.h"
#include "FreightVehicle.h"
#include <iostream>

LogisticsOrder::LogisticsOrder(double w) : weight(w) {}

void LogisticsOrder::assignVehicle(Vehicle v) {
    if (weight < 0) {
        throw invalid_argument("Вес не может быть отрицательным.");
    }
    if (weight > v.getCargoCapacity()) {
        throw invalid_argument("Вес превышает грузоподъемность.");
    }
    cout << "Транспортное средство назначено успешно." << std::endl;
}

double LogisticsOrder::getWeight() {
    return weight;
}
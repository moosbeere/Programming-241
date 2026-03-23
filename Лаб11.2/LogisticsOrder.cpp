#include "LogisticsOrder.h"

LogisticsOrder::LogisticsOrder(double w) : weight(w) {}

void LogisticsOrder::assignVehicle(Vehicle& v) {
    if (weight <= 0) {
        throw invalid_argument("Вес не может быть отрицательным");
    }

    if (v.getCargoCapacity() <= 0) {
        throw invalid_argument("Вместимость не может отрицательной");
    }

    if (weight > v.getCargoCapacity()) {
        throw invalid_argument("Перегруз!");
    }
}
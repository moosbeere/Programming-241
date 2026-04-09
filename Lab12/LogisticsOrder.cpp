#include "LogisticsOrder.h"
#include "FreightVehicle.h"
#include <iostream>
#include <exception>

LogisticsOrder::LogisticsOrder(double w) : weight(w) {}

void LogisticsOrder::assignVehicle(Vehicle& v) {
    if (weight < 0) {
        throw invalid_argument("Вес не может быть отрицательным.");
    }
    // Проверяем, является ли ТС грузовым
    FreightVehicle* freight = dynamic_cast<FreightVehicle*>(&v);
    if (!freight) {
        throw invalid_argument("Транспортное средство не является грузовым.");
    }
    if (weight > freight->getCargoCapacity()) {
        throw overflow_error("Вес превышает грузоподъемность.");
    }
    cout << "Транспортное средство назначено успешно." << endl;
}

double LogisticsOrder::getWeight() const {
    return weight;
}
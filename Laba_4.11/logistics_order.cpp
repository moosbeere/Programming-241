#include "logistics_order.h"
#include <iostream>

LogisticsOrder::LogisticsOrder(double w) : weight(w) {
}

void LogisticsOrder::assignVehicle(const FreightVehicle& vehicle) {
    if (weight < 0) {
        throw invalid_argument("Ошибка: Вес заказа не может быть отрицательным!");
    }

    if (weight > vehicle.getCargoCapacity()) {
        throw invalid_argument("Ошибка: Вес груза превышает грузоподъемность машины " + vehicle.getName() + "!");
    }

    cout << "Заказ весом " << weight << " кг назначен на " << vehicle.getName() << endl;
}

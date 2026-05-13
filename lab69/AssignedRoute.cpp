#include "AssignedRoute.h"

// ======================================================
// Конструктор
// ======================================================

AssignedRoute::AssignedRoute(Route r,
    unique_ptr<Vehicle> t)

    : route(r),
    transport(move(t)) {
}

// ======================================================
// Расчет стоимости
// ======================================================

double AssignedRoute::calculateTotalCost() const {

    return transport->calculateToll(
        route.getLength()
    );
}

// ======================================================
// Вывод информации
// ======================================================

void AssignedRoute::printInfo() const {

    route.printInfo();

    cout << "Стоимость: "
        << calculateTotalCost()
        << " у.е."
        << endl;
}
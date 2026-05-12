#include <iostream>
#include "AssignedRoute.h"

using namespace std;


// Конструктор


AssignedRoute::AssignedRoute(Route r, TransportUnit* t)
    : route(r) {

    transport = t;
}


// Расчет полной стоимости


double AssignedRoute::calculateTotalCost() const {

    // Полиморфный вызов
    return transport->calculateToll(route.getLength());
}


// Вывод информации


void AssignedRoute::printAssignedInfo() const {

    route.printInfo();

    cout << "Стоимость проезда: "
        << calculateTotalCost()
        << " у.е."
        << endl;
}
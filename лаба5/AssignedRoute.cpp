#include "AssignedRoute.h"
#include <iostream>

AssignedRoute::AssignedRoute(const Route& r, const TransportUnit* t)
    : route(r), transport(t) {}

double AssignedRoute::calculateTotalCost() const {
    if (transport)
        return transport->calculateToll(route.getLength());
    else
        return 0.0;
}

void AssignedRoute::printAssignedInfo() const {
    route.printInfo();
    std::cout << "Общая стоимость проезда: " << calculateTotalCost() << " у.е." << std::endl;
}
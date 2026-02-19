#include "AssignedRoute.h"
#include <iostream>

AssignedRoute::AssignedRoute(const Route& r, unique_ptr<TransportUnit> t)
    : route(r), transport(std::move(t)) {
}

double AssignedRoute::calculateTotalCost() const {
    return transport->calculateToll(route.getLength());
}

void AssignedRoute::printInfo() const {
    route.printInfo();
    std::cout << "Транспорт: " << transport->getDescription() << std::endl;
}
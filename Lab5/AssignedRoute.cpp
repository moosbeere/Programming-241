#include "AssignedRoute.h"
#include <iostream>

using namespace std;

AssignedRoute::AssignedRoute(const Route& r, TransportUnit* t)
    : route(r), transport(t) {
}

double AssignedRoute::calculateTotalCost() const {
    return transport->calculateToll(route.getLength());
}

void AssignedRoute::printInfo() const {
    route.printInfo();
    cout << "Транспорт: " << transport->getDescription() << endl;
}
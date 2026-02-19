#pragma once
#include "Route.h"
#include "TransportUnit.h"

class AssignedRoute {
private:
    Route route;
    TransportUnit* transport;
public:
    AssignedRoute(const Route& r, TransportUnit* t);
    double calculateTotalCost() const;
    void printInfo() const;
};
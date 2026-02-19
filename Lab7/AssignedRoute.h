#pragma once
#include "Route.h"
#include "TransportUnit.h"
#include <memory>

class AssignedRoute {
private:
    Route route;
    unique_ptr<TransportUnit> transport;
public:
    AssignedRoute(const Route& r, unique_ptr<TransportUnit> t);
    double calculateTotalCost() const;
    void printInfo() const;
};
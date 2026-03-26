#pragma once
#include "Route.h"
#include "TransportUnit.h"

class AssignedRoute {
private:
    Route route;                  
    const TransportUnit* transport;
public:
    AssignedRoute(const Route& r, const TransportUnit* t);
    double calculateTotalCost() const;
    void printAssignedInfo() const;
};


#pragma once
#include "Route.h"
#include "TransportUnit.h"

class AssignedRoute {
private:
    Route route;                  // композиция
    const TransportUnit* transport; // агрегация (указатель, не владеет)
public:
    AssignedRoute(const Route& r, const TransportUnit* t);
    double calculateTotalCost() const;
    void printAssignedInfo() const;
};


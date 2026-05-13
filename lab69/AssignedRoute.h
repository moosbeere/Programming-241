#pragma once
#ifndef ASSIGNEDROUTE_H
#define ASSIGNEDROUTE_H

#include <memory>

#include "Route.h"
#include "Vehicle.h"

using namespace std;

// ======================================================
// Класс AssignedRoute
// ======================================================

class AssignedRoute {
private:

    Route route;

    // unique_ptr
    unique_ptr<Vehicle> transport;

public:

    AssignedRoute(Route r, unique_ptr<Vehicle> t);

    double calculateTotalCost() const;

    void printInfo() const;
};

#endif
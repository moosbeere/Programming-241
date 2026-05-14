#pragma once
#ifndef ASSIGNEDROUTE_H
#define ASSIGNEDROUTE_H

#include <memory>
#include "TransportUnit.h"
#include "Route.h"

class AssignedRoute {
private:
    Route route;
    std::unique_ptr<TransportUnit> transport;

public:
    AssignedRoute(std::unique_ptr<TransportUnit> transport,
        const Route& route);

    double calculateTotalCost() const;
    void showInfo() const;
};

#endif
#include <iostream>
#include "AssignedRoute.h"

AssignedRoute::AssignedRoute(std::unique_ptr<Vehicle> vehicle,
    const Route& route)
    : vehicle(std::move(vehicle)), route(route)
{
}

void AssignedRoute::showAssignment() const {
    vehicle->info();
    route.showRoute();
}
#include "bus.h"
#include <iostream>

Bus::Bus(std::string n,
    double maxSpd,
    int route,
    int capacity,
    std::string fuel)
    : Vehicle(n, maxSpd),
    PublicTransport(route, capacity)
{
    fuelType = fuel;
}

void Bus::info() const
{
    std::cout << "Автобус | тип топлива: "
        << fuelType
        << " | маршрут: "
        << routeNumber
        << std::endl;
}
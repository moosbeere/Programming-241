#include "publictransport.h"
#include <iostream>

PublicTransport::PublicTransport(int route, int capacity)
{
    routeNumber = route;
    passengerCapacity = capacity;
}

void PublicTransport::showRoute() const
{
    std::cout << "Route: " << routeNumber
        << " | Passengers: " << passengerCapacity
        << std::endl;
}
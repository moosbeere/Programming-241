#include "tram.h"
#include <iostream>

Tram::Tram(int route,
    int capacity,
    int voltage)
    : PublicTransport(route, capacity)
{
    electricLineVoltage = voltage;
}

void Tram::info() const
{
    std::cout << "Трамвай | маршрут: "
        << routeNumber
        << " | напряжение линии: "
        << electricLineVoltage
        << std::endl;
}
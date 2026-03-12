#pragma once

#include "route.h"
#include "transport_unit.h"

// Класс "Назначенный маршрут" (композиция + агрегация) с "сырым" указателем.
class AssignedRoute
{
private:
    Route route;              // композиция: маршрут - часть объекта
    TransportUnit* transport; // агрегация: внешний по управлению объект

public:
    AssignedRoute(const Route& route, TransportUnit* transport)
        : route(route),
          transport(transport)
    {
    }

    // Стоимость поездки по маршруту данным транспортом.
    double calculateTotalCost() const
    {
        if (!transport)
            return 0.0;
        return transport->calculateToll(route.getLength());
    }

    void printFullInfo() const
    {
        route.printInfo();
        std::cout << "  total cost: " << calculateTotalCost() << " units\n";
    }
};


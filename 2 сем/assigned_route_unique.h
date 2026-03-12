#pragma once

#include <memory>

#include "route.h"
#include "transport_unit.h"

// Класс "Назначенный маршрут" с владением транспортом через std::unique_ptr.
class AssignedRouteUnique
{
private:
    Route route;                               // композиция
    std::unique_ptr<TransportUnit> transport;  // владение транспортом

public:
    AssignedRouteUnique(const Route& route,
                        std::unique_ptr<TransportUnit> transport)
        : route(route),
          transport(std::move(transport))
    {
    }

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


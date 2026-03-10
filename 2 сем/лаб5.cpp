#include <iostream>
#include <string>

#include "transport_unit.h"

// Класс "Маршрут" (композиция)
class Route
{
private:
    std::string startPoint;
    std::string endPoint;
    double length; // в км

public:
    Route(const std::string& startPoint,
          const std::string& endPoint,
          double length)
        : startPoint(startPoint),
          endPoint(endPoint),
          length(length < 0 ? 0.0 : length)
    {
    }

    double getLength() const
    {
        return length;
    }

    void printInfo() const
    {
        std::cout << "Route info:\n";
        std::cout << "  from: " << startPoint << "\n";
        std::cout << "  to:   " << endPoint << "\n";
        std::cout << "  length: " << length << " km\n";
    }
};

// Класс "Назначенный маршрут" (композиция + агрегация)
class AssignedRoute
{
private:
    Route route;                 // композиция: маршрут - часть объекта
    TransportUnit* transport;    // агрегация: внешний по управлению объект

public:
    AssignedRoute(const Route& route, TransportUnit* transport)
        : route(route),
          transport(transport)
    {
    }

    // Стоимость поездки по маршруту данным транспортом
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

int main()
{
    // Создаём несколько единиц транспорта
    Car car;
    Truck truck;

    // Создаём маршруты
    Route shortRoute("City A", "City B", 50.0);
    Route longRoute("City C", "City D", 300.0);

    // Назначаем маршруты разным видам транспорта
    AssignedRoute ar1(shortRoute, &car);
    AssignedRoute ar2(shortRoute, &truck);
    AssignedRoute ar3(longRoute, &car);
    AssignedRoute ar4(longRoute, &truck);

    std::cout << "=== Assigned routes ===\n\n";

    ar1.printFullInfo();
    std::cout << "\n";

    ar2.printFullInfo();
    std::cout << "\n";

    ar3.printFullInfo();
    std::cout << "\n";

    ar4.printFullInfo();
    std::cout << "\n";

    return 0;
}

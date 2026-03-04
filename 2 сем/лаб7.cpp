#include <iostream>
#include <string>
#include <memory>

// Базовый абстрактный класс (как в заданиях 4 и 5)
class TransportUnit
{
public:
    virtual double calculateToll(double distance) const = 0;
    virtual ~TransportUnit() = default;
};

class Car : public TransportUnit
{
public:
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.1;
    }
};

class Truck : public TransportUnit
{
public:
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.3 + 5.0;
    }
};

// Класс "Маршрут"
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

// Класс "Назначенный маршрут" с умным указателем
class AssignedRoute
{
private:
    Route route;                               // композиция
    std::unique_ptr<TransportUnit> transport;  // владение транспортом

public:
    AssignedRoute(const Route& route,
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

int main()
{
    Route route1("City A", "City B", 120.0);
    Route route2("City C", "City D", 300.0);

    // Создаём AssignedRoute, передавая во владение динамически созданные объекты
    AssignedRoute arCar(route1, std::make_unique<Car>());
    AssignedRoute arTruck(route2, std::make_unique<Truck>());

    std::cout << "=== Assigned routes with std::unique_ptr ===\n\n";

    arCar.printFullInfo();
    std::cout << "\n";

    arTruck.printFullInfo();
    std::cout << "\n";

    // Никакого delete вызывать не нужно — std::unique_ptr сам освободит память

    return 0;
}

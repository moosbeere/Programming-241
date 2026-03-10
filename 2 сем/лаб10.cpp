#include <iostream>
#include <string>

#include "vehicle.h"

// Базовый класс "Общественный транспорт"
class PublicTransport
{
protected:
    int routeNumber;          // номер маршрута
    int passengerCapacity;    // вместимость пассажиров

public:
    PublicTransport(int routeNumber, int passengerCapacity)
        : routeNumber(routeNumber),
          passengerCapacity(passengerCapacity < 0 ? 0 : passengerCapacity)
    {
    }

    virtual void printInfo() const
    {
        std::cout << "Route #" << routeNumber
                  << ", capacity: " << passengerCapacity << " passengers\n";
    }

    virtual ~PublicTransport() = default;
};

// Автобус: и общественный транспорт, и обычное транспортное средство
// Здесь используем МНОЖЕСТВЕННОЕ наследование:
// - PublicTransport отвечает за маршрут и пассажиров
// - Vehicle отвечает за марку и скорость
class Bus : public PublicTransport, public Vehicle
{
private:
    std::string fuelType; // тип топлива (дизель, газ, электро и т.п.)

public:
    Bus(int routeNumber,
        int passengerCapacity,
        const std::string& brand,
        int maxSpeed,
        const std::string& fuelType)
        : PublicTransport(routeNumber, passengerCapacity),
          Vehicle(brand, maxSpeed),
          fuelType(fuelType)
    {
    }

    void printInfo() const override
    {
        std::cout << "[Bus]\n";
        PublicTransport::printInfo();
        std::cout << "  brand: " << getBrand() << "\n";
        std::cout << "  maxSpeed: " << getMaxSpeed() << "\n";
        std::cout << "  fuelType: " << fuelType << "\n";
    }
};

// Трамвай: только общественный транспорт, без наследования от Vehicle
class Tram : public PublicTransport
{
private:
    int electricLineVoltage; // напряжение контактной сети, В

public:
    Tram(int routeNumber,
         int passengerCapacity,
         int electricLineVoltage)
        : PublicTransport(routeNumber, passengerCapacity),
          electricLineVoltage(electricLineVoltage)
    {
    }

    void printInfo() const override
    {
        std::cout << "[Tram]\n";
        PublicTransport::printInfo();
        std::cout << "  electric line voltage: "
                  << electricLineVoltage << " V\n";
    }
};

int main()
{
    Bus bus(12, 80, "MAN", 90, "diesel");
    Tram tram(5, 150, 600);

    std::cout << "=== Public transport info ===\n\n";

    bus.printInfo();
    std::cout << "\n";

    tram.printInfo();

    return 0;
}

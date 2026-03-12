#pragma once

#include <stdexcept>

#include "freight_vehicle.h"

// Логистический заказ.
class LogisticsOrder
{
private:
    double weight;             // вес груза в тоннах
    const Vehicle* vehiclePtr; // назначенное транспортное средство (может быть nullptr)

public:
    explicit LogisticsOrder(double weight)
        : weight(weight), vehiclePtr(nullptr)
    {
    }

    void assignVehicle(Vehicle& v)
    {
        // Проверяем корректность веса заказа.
        if (weight < 0.0)
        {
            throw std::invalid_argument("Order weight cannot be negative");
        }

        // Пытаемся привести к FreightVehicle, так как только он имеет грузоподъёмность.
        auto* freight = dynamic_cast<FreightVehicle*>(&v);
        if (!freight)
        {
            throw std::invalid_argument("Assigned vehicle is not a freight vehicle");
        }

        if (weight > freight->getCargoCapacity())
        {
            throw std::invalid_argument("Order weight exceeds vehicle cargo capacity");
        }

        vehiclePtr = &v; // успешное назначение
    }

    void printInfo() const
    {
        std::cout << "Order weight: " << weight << " tons\n";
        if (vehiclePtr)
        {
            std::cout << "Assigned vehicle:\n";
            vehiclePtr->getStatus();
        }
        else
        {
            std::cout << "No vehicle assigned.\n";
        }
    }
};


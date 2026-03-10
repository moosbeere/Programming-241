#include <iostream>
#include <string>
#include <stdexcept>

#include "vehicle.h"

// Грузовой транспорт, использующий общий Vehicle как базу
class FreightVehicle : public Vehicle
{
private:
    double cargoCapacity; // грузоподъёмность в тоннах

public:
    FreightVehicle(const std::string& brand, int maxSpeed, double cargoCapacity)
        : Vehicle(brand, maxSpeed),
          cargoCapacity(cargoCapacity < 0 ? 0.0 : cargoCapacity)
    {
    }

    double getCargoCapacity() const
    {
        return cargoCapacity;
    }

    void getStatus() const override
    {
        Vehicle::getStatus();
        std::cout << "  cargoCapacity: " << cargoCapacity << " tons\n";
    }
};

// Логистический заказ
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
        // Проверяем корректность веса заказа
        if (weight < 0.0)
        {
            throw std::invalid_argument("Order weight cannot be negative");
        }

        // Пытаемся привести к FreightVehicle, так как только он имеет грузоподъёмность
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

int main()
{
    FreightVehicle truckSmall("MAN", 110, 3.0);
    FreightVehicle truckBig("Volvo", 120, 10.0);

    LogisticsOrder order1(2.5);   // корректный вес, поместится в оба
    LogisticsOrder order2(8.0);   // поместится только в большой грузовик
    LogisticsOrder order3(-1.0);  // некорректный вес

    std::cout << "=== Logistics orders and vehicle assignment ===\n\n";

    // 1. Успешное назначение
    try
    {
        std::cout << "Assigning order1 to truckSmall...\n";
        order1.assignVehicle(truckSmall);
        order1.printInfo();
        std::cout << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error while assigning order1: " << ex.what() << "\n\n";
    }

    // 2. Ошибка: вес больше грузоподъёмности
    try
    {
        std::cout << "Assigning order2 to truckSmall...\n";
        order2.assignVehicle(truckSmall);
        order2.printInfo();
        std::cout << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error while assigning order2 to small truck: "
                  << ex.what() << "\n\n";
    }

    // 3. Успешное назначение тяжелого заказа на большой грузовик
    try
    {
        std::cout << "Assigning order2 to truckBig...\n";
        order2.assignVehicle(truckBig);
        order2.printInfo();
        std::cout << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error while assigning order2 to big truck: "
                  << ex.what() << "\n\n";
    }

    // 4. Ошибка: отрицательный вес
    try
    {
        std::cout << "Assigning order3 to truckBig...\n";
        order3.assignVehicle(truckBig);
        order3.printInfo();
        std::cout << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error while assigning order3: " << ex.what() << "\n\n";
    }

    return 0;
}

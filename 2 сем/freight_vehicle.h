#pragma once

#include <string>

#include "vehicle.h"

// Класс "Грузовой транспорт", наследуется от Vehicle.
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


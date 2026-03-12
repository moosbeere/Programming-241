#pragma once

#include <iostream>
#include <string>

#include "vehicle.h"

// Диспетчерский центр.
class DispatchCenter
{
public:
    // Общее количество "обслуженных" (зарегистрированных) транспортных средств.
    static int totalVehiclesDispatched;

    // Отчёт по количеству.
    static void report()
    {
        std::cout << "Total vehicles dispatched: "
                  << totalVehiclesDispatched << "\n";
    }
};

// Обязательное определение статического поля.
inline int DispatchCenter::totalVehiclesDispatched = 0;

// Класс-обёртка над Vehicle для учёта в диспетчерской.
class CountedVehicle : public Vehicle
{
public:
    CountedVehicle(const std::string& brand, int maxSpeed)
        : Vehicle(brand, maxSpeed)
    {
        // Каждый созданный объект регистрируется в диспетчерской.
        DispatchCenter::totalVehiclesDispatched++;
    }
};


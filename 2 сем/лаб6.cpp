#include <iostream>
#include <string>

#include "vehicle.h"

// Диспетчерский центр
class DispatchCenter
{
public:
    // Общее количество "обслуженных" (зарегистрированных) транспортных средств
    static int totalVehiclesDispatched;

    // Отчёт по количеству
    static void report()
    {
        std::cout << "Total vehicles dispatched: "
                  << totalVehiclesDispatched << "\n";
    }
};

// Обязательное определение статического поля
int DispatchCenter::totalVehiclesDispatched = 0;

// Класс-обёртка над Vehicle для учёта в диспетчерской
class CountedVehicle : public Vehicle
{
public:
    CountedVehicle(const std::string& brand, int maxSpeed)
        : Vehicle(brand, maxSpeed)
    {
        // Каждый созданный объект регистрируется в диспетчерской
        DispatchCenter::totalVehiclesDispatched++;
    }
};

int main()
{
    std::cout << "Before creating vehicles:\n";
    DispatchCenter::report();

    CountedVehicle v1("Toyota", 180);
    CountedVehicle v2("BMW", 220);
    CountedVehicle v3("Volvo", 160);

    std::cout << "\nAfter creating 3 vehicles:\n";
    DispatchCenter::report();

    {
        CountedVehicle v4("Mercedes", 200);
        CountedVehicle v5("Audi", 210);
        std::cout << "\nAfter creating 2 more vehicles in inner scope:\n";
        DispatchCenter::report();
    }

    std::cout << "\nAfter inner scope ends (objects destroyed, счётчик не уменьшается):\n";
    DispatchCenter::report();

    return 0;
}

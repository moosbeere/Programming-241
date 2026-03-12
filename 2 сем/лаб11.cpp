#include <iostream>

#include "logistics_order.h"

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

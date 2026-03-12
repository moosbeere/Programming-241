#include <iostream>
#include <string>

#include "transport_unit.h"
#include "route.h"
#include "assigned_route.h"

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

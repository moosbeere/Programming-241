#include <iostream>
#include <string>
#include <memory>

#include "transport_unit.h"
#include "route.h"
#include "assigned_route_unique.h"

int main()
{
    Route route1("City A", "City B", 120.0);
    Route route2("City C", "City D", 300.0);

    // Создаём AssignedRouteUnique, передавая во владение динамически созданные объекты
    AssignedRouteUnique arCar(route1, std::make_unique<Car>());
    AssignedRouteUnique arTruck(route2, std::make_unique<Truck>());

    std::cout << "=== Assigned routes with std::unique_ptr ===\n\n";

    arCar.printFullInfo();
    std::cout << "\n";

    arTruck.printFullInfo();
    std::cout << "\n";

    // Никакого delete вызывать не нужно — std::unique_ptr сам освободит память

    return 0;
}

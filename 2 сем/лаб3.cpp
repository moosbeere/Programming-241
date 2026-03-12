#include <iostream>

#include "freight_vehicle.h"

int main()
{
    // Примеры использования грузового транспорта
    FreightVehicle truck1("Volvo", 120, 20.5);
    FreightVehicle truck2("MAN", 110, 15.0);

    std::cout << "=== Initial status ===\n";
    truck1.getStatus();
    truck2.getStatus();

    // Немного "едем": ускоряем и тормозим
    truck1.accelerate(60);
    truck2.accelerate(80);
    truck2.brake(30);

    std::cout << "=== After movement ===\n";
    truck1.getStatus();
    truck2.getStatus();

    return 0;
}

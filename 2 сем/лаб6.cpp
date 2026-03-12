#include <iostream>

#include "dispatch_center.h"

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

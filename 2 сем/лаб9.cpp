#include <algorithm>
#include <iostream>
#include <vector>

#include "vehicle.h"

int main()
{
    // Массив транспортных средств с разной максимальной скоростью
    std::vector<Vehicle> vehicles = {
        Vehicle("Toyota", 180),
        Vehicle("BMW", 250),
        Vehicle("Lada", 140),
        Vehicle("Mercedes", 220),
        Vehicle("Volkswagen", 200)
    };

    // Сортировка использует перегруженный operator< (сравнение по maxSpeed)
    std::sort(vehicles.begin(), vehicles.end());

    std::cout << "=== Vehicles sorted by maxSpeed (ascending) ===\n\n";
    for (const auto& v : vehicles)
    {
        std::cout << v.getBrand() << " | maxSpeed = " << v.getMaxSpeed() << "\n";
    }

    return 0;
}

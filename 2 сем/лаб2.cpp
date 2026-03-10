#include <iostream>
#include <vector>

#include "vehicle.h"

int main()
{
    // Массив из 5 различных транспортных средств
    std::vector<Vehicle> vehicles = {
        Vehicle("Toyota", 180),
        Vehicle("BMW", 250),
        Vehicle("Lada", 140),
        Vehicle("Mercedes", 220),
        Vehicle("Volkswagen", 200)
    };

    // Симмулируем движение: ускоряем каждое с разными значениями
    vehicles[0].accelerate(80);
    vehicles[1].accelerate(120);
    vehicles[2].accelerate(60);
    vehicles[3].accelerate(200);
    vehicles[4].accelerate(150);

    // Для некоторых — торможение
    vehicles[0].brake(30);
    vehicles[2].brake(40);
    vehicles[4].brake(50);

    // В конце выводим статус всех транспортных средств
    std::cout << "=== Итоговый статус всех транспортных средств ===\n\n";
    for (size_t i = 0; i < vehicles.size(); ++i)
    {
        vehicles[i].getStatus();
    }

    return 0;
}
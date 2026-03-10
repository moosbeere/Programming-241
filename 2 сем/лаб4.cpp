#include <iostream>
#include <vector>

#include "transport_unit.h"

int main()
{
    const double distance = 100.0; // расстояние в км

    // Можем хранить разные типы транспорта в одном контейнере указателей на базовый класс
    std::vector<TransportUnit*> units;
    units.push_back(new Car());
    units.push_back(new Truck());
    units.push_back(new Car());
    units.push_back(new Truck());

    std::cout << "Distance: " << distance << " km\n\n";

    for (std::size_t i = 0; i < units.size(); ++i)
    {
        double toll = units[i]->calculateToll(distance);
        std::cout << "TransportUnit #" << i + 1
                  << " toll = " << toll << " units\n";
    }

    // Освобождаем память
    for (TransportUnit* u : units)
    {
        delete u;
    }

    return 0;
}

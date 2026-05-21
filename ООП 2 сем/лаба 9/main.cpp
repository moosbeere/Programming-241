#include <iostream>
#include <vector>
#include <algorithm>
#include "Vehicle.h"

int main() {
    std::vector<Vehicle> vehicles = {
        Vehicle("Мопед", 60),
        Vehicle("Легковой автомобиль", 180),
        Vehicle("Спорткар", 320),
        Vehicle("Грузовик", 110),
        Vehicle("Электромобиль", 150)
    };

    std::cout << "До сортировки:\n";
    for (const auto& v : vehicles) {
        v.print();
        std::cout << std::endl;
    }

    std::sort(vehicles.begin(), vehicles.end());

    std::cout << "\nПосле сортировки (по возрастанию maxSpeed):\n";
    for (const auto& v : vehicles) {
        v.print();
        std::cout << std::endl;
    }

    return 0;
}

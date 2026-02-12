#include <iostream>
#include "Car.h"
#include "Truck.h"

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 2;
    TransportUnit* units[size];

    units[0] = new Car();
    units[1] = new Truck();

    double distance = 100.0;

    for (int i = 0; i < size; ++i) {
        std::cout << "Плата для транспорта " << i + 1 << ": "
            << units[i]->calculateToll(distance) << " у.е.\n";
    }

    return 0;
}
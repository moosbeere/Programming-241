#include <iostream>
#include "Car.h"
#include "Truck.h"

int main() {
    
    TransportUnit* units[4];

    // Создаём объекты производных классов
    units[0] = new Car();
    units[1] = new Truck();
    units[2] = new Car();
    units[3] = new Truck();

    double distance = 100.0;  

    // Вычисляем и выводим плату для каждого объекта
    for (int i = 0; i < 4; ++i) {
        double toll = units[i]->calculateToll(distance);
        std::cout << "Плата для объекта " << i << ": " << toll << " у.е." << std::endl;
    }

   
    for (int i = 0; i < 4; ++i) {
        delete units[i];
    }

    return 0;
}

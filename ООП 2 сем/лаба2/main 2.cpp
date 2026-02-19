#include <iostream>
#include <vector>
#include "Vehicle.h"

int main() {
    // 1. Создаём парк из 5 различных транспортных средств
    std::vector<Vehicle> park;
    park.push_back(Vehicle("Toyota", 180));
    park.push_back(Vehicle("BMW", 240));
    park.push_back(Vehicle("Lada", 150));
    park.push_back(Vehicle("Tesla", 200));
    park.push_back(Vehicle("Ford", 190));

    // 2. Выводим начальное состояние (все скорости = 0)
    std::cout << "=== Начальное состояние парка ===\n";
    for (const auto& v : park) {
        v.getStatus();
    }

    // 3. Ускоряем каждое транспортное средство на разное значение
    int increments[] = {30, 50, 100, 70, 20}; // значения для пяти машин
    std::cout << "\n=== Ускорение ===\n";
    for (size_t i = 0; i < park.size(); ++i) {
        park[i].accelerate(increments[i]);
        std::cout << "Ускорили " << park[i].getBrand()
            
    std::cout << "Состояние после ускорения:\n";
    for (const auto& v : park) {
        v.getStatus();
    }

    // 4. Некоторые транспортные средства тормозят
    std::cout << "\n=== Торможение (для отдельных машин) ===\n";
    park[1].brake(80);   // BMW замедляется на 80 км/ч
    park[3].brake(150);  // Tesla замедляется на 150 км/ч
    park[4].brake(30);   // Ford замедляется на 30 км/ч

    // 5. Итоговое состояние всего парка
    std::cout << "\n=== Итоговое состояние парка ===\n";
    for (const auto& v : park) {
        v.getStatus();
    }

    return 0;

}

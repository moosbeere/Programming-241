#include <iostream>
#include "AssignedRoute.h"
#include "TransportUnit.h"

int main() {
    Bus bus;

    // Создаём назначенный маршрут: композиция Route создаётся внутри, агрегация – указатель на bus
    AssignedRoute assigned("Москва", "Санкт-Петербург", 705.0, &bus);

  
    assigned.printInfo();

    return 0;
}

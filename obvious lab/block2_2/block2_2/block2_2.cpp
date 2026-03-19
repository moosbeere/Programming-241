#include <iostream>
#include <memory>
#include "Route.h"
#include "Unit.h"


int main() {
    setlocale(LC_ALL, "RU");

    
    Route route1("Москва", "Питер", 700);
    Route route2("Казань", "Москва", 800);

    
    AssignedRoute trip1(route1, std::make_unique<Car>("A123BC"));
    AssignedRoute trip2(route2, std::make_unique<Truck>(20.5, "B456CD"));
    AssignedRoute trip3(route1, std::make_unique<Car>("C789EF"));

    
    trip1.printInfo();
    trip2.printInfo();
    trip3.printInfo();

    return 0;
}
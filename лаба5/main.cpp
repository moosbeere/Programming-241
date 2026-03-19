#include <iostream>
#include "Car.h"
#include "AssignedRoute.h"

int main() {
    Car car;
    Route route("Москва", "Санкт-Петербург", 700.0);

    AssignedRoute assigned(route, &car);

    assigned.printAssignedInfo();

    return 0;
}
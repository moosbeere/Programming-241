#include <iostream>
#include <memory>
#include "Route.h"
#include "AssignedRoute.h"
#include "Car.h"
#include "Truck.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Route route("Москва", "Санкт-Петербург", 700.0);

    auto car = make_unique<Car>();
    auto truck = make_unique<Truck>();

    AssignedRoute route1(route, move(car));
    AssignedRoute route2(route, move(truck));

    cout << "Маршрут 1:\n";
    route1.printInfo();
    cout << "Стоимость проезда: " << route1.calculateTotalCost() << " руб.\n\n";

    cout << "Маршрут 2:\n";
    route2.printInfo();
    cout << "Стоимость проезда: " << route2.calculateTotalCost() << " руб.\n";

    return 0;
}
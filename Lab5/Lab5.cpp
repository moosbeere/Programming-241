#include <iostream>
#include "Route.h"
#include "AssignedRoute.h"
#include "Car.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Route route("Центр", "Вокзал", 100);
    Car car("тойота");
    AssignedRoute assigned1(route, &car);

    assigned1.printInfo();
    cout << "Стоимость проезда: "
        << assigned1.calculateTotalCost() << " руб.\n\n";

    return 0;
}
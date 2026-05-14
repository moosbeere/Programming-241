#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "DispatchCenter.h"
#include "Car.h"
#include "Truck.h"
#include "Route.h"
#include "AssignedRoute.h"
#include "Warehouse.h"

int main() {

    std::cout << "=== Task 6 ===" << std::endl;

    Car car1("Toyota", 180);
    Truck truck1("Volvo", 120);

    DispatchCenter::report();

    std::cout << std::endl;

    std::cout << "=== Task 7 ===" << std::endl;

    Route route1("Berlin");

    AssignedRoute assigned(
        std::make_unique<Truck>("MAN", 110),
        route1
    );

    assigned.showAssignment();

    std::cout << std::endl;

    std::cout << "=== Task 8 ===" << std::endl;

    Warehouse<int> numberWarehouse;

    numberWarehouse.addItem(101);
    numberWarehouse.addItem(202);

    std::cout << "Numbers warehouse items: "
        << numberWarehouse.getTotalItems()
        << std::endl;

    std::cout << "First item: "
        << numberWarehouse.getItem(0)
        << std::endl;

    Warehouse<std::string> stringWarehouse;

    stringWarehouse.addItem("Food");
    stringWarehouse.addItem("Electronics");

    std::cout << "String warehouse items: "
        << stringWarehouse.getTotalItems()
        << std::endl;

    std::cout << "First item: "
        << stringWarehouse.getItem(0)
        << std::endl;

    std::cout << std::endl;

    std::cout << "=== Task 9 ===" << std::endl;

    std::vector<Vehicle> vehicles;

    vehicles.push_back(Vehicle("Bike", 60));
    vehicles.push_back(Vehicle("Bus", 90));
    vehicles.push_back(Vehicle("SportCar", 250));

    std::sort(vehicles.begin(), vehicles.end());

    for (const auto& v : vehicles) {
        v.info();
    }

    return 0;
}
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

    std::cout << "TASK 4" << std::endl;

    std::vector<TransportUnit*> v;

    v.push_back(new Car("BMW", 220));
    v.push_back(new Truck("Volvo", 120));

    for (auto x : v) {
        x->info();
        std::cout << x->calculateToll(100) << std::endl;
    }

    std::cout << "\nTASK 5" << std::endl;

    Route r("A", "B", 150);

    AssignedRoute ar(
        std::make_unique<Truck>("MAN", 110),
        r
    );

    ar.showInfo();

    std::cout << "\nTASK 6" << std::endl;

    DispatchCenter::report();

    std::cout << "\nTASK 8" << std::endl;

    Warehouse<int> w1;
    w1.addItem(10);
    w1.addItem(20);

    std::cout << w1.getTotalItems() << std::endl;

    Warehouse<std::string> w2;
    w2.addItem("Box");

    std::cout << w2.getItem(0) << std::endl;

    std::cout << "\nTASK 9" << std::endl;

    Car c1("Audi", 240);
    Car c2("Toyota", 180);
    Truck t1("Big", 90);

    std::vector<TransportUnit*> arr;
    arr.push_back(&c1);
    arr.push_back(&c2);
    arr.push_back(&t1);

    std::sort(arr.begin(), arr.end(),
        [](TransportUnit* a, TransportUnit* b) {
            return *a < *b;
        });

    for (auto a : arr) {
        a->info();
    }

    for (auto x : v) delete x;

    return 0;
}
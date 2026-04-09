#include <iostream>
#include <memory>
#include "TrafficFlow.h"
#include "RoadSegment.h"
#include "Car.h"
#include "FreightVehicle.h"
#include "Truck.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    RoadSegment road(15.0, 90.0);
    road.printInfo();

    TrafficFlow flow;

    flow.addVehicle(make_unique<Car>("Toyota", 180));
    flow.addVehicle(make_unique<Car>("Ford", 160));

    flow.addVehicle(make_unique<FreightVehicle>("Volvo", 120, 20.0));
    flow.addVehicle(make_unique<FreightVehicle>("MAN", 110, 25.0));

    flow.addVehicle(make_unique<Truck>("Kenworth", 105));

    double timeStep = 1;
    int steps = 3;

    for (int step = 1; step <= steps; ++step) {
         cout << "\nШаг " << step << " (время " << step * timeStep << " ч)\n";
        flow.simulate(timeStep, road);
        flow.printStatus();
    }

    return 0;
}
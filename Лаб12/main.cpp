#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "TrafficFlow.h"
#include "RoadSegment.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    RoadSegment road(500, 30);

    TrafficFlow flow;

    flow.addVehicle(make_unique<Car>());
    flow.addVehicle(make_unique<Truck>());
    flow.addVehicle(make_unique<Motorcycle>());

    flow.simulate(10, 1, road);

    return 0;
}
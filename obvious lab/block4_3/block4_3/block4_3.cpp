#include <iostream>
#include <memory>
#include "Car.h"
#include "Truck.h"
#include "RoadSegment.h"
#include "TrafficFlow.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    RoadSegment road(1000, 90);
    road.Info();

    TrafficFlow flow;

    flow.addVehicle(make_unique<Car>("Toyota"));
    flow.addVehicle(make_unique<Truck>("KamAZ", 15));
    flow.addVehicle(make_unique<Car>("BMW"));
    flow.addVehicle(make_unique<Truck>("Volvo", 20));

    cout << "\nВсего машин: " << flow.getVehicleCount() << endl;

    for (int step = 0; step <= 10; ++step) {
        cout << "\n--- Время: " << step << " с ---" << endl;
        flow.printStatus();

        if (step < 10) {
            flow.simulate(1.0, road);
        }
    }

    return 0;
}
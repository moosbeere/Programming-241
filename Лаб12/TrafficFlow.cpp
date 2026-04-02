#include "TrafficFlow.h"
#include <iostream>

using namespace std;

void TrafficFlow::addVehicle(unique_ptr<Vehicle> v) {
    vehicles.push_back(move(v));
}

void TrafficFlow::simulate(double totalTime, double dt, const RoadSegment& road) {
    for (double t = 0; t <= totalTime; t += dt) {
        cout << "Момент: " << t << " секунда" << endl;

        for (int i = 0; i < vehicles.size(); i++) {
            Vehicle* currentVehicle = vehicles[i].get();
            currentVehicle->simulate(dt, road.getSpeedLimit());
            if (currentVehicle->getPosition() <= road.getLength()) {
                cout << currentVehicle->getType() << ". Позиция: " << currentVehicle->getPosition() << " м" << endl;
            }
        }
        cout << "-------------------" << endl;
    }
}
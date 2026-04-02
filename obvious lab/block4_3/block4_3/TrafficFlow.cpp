#include "TrafficFlow.h"
#include <iostream>
using namespace std;

void TrafficFlow::addVehicle(unique_ptr<Vehicle> vehicle) {
    vehicles.push_back(move(vehicle));
}

void TrafficFlow::simulate(double timeStep, const RoadSegment& road) {
    int limit = road.getMaxAllowedSpeed();

    for (auto& v : vehicles) {
        if (v->getCurrentSpeed() < limit) {
            v->accelerate(5);
        }
        else if (v->getCurrentSpeed() > limit) {
            v->brake(5);
        }
    }
}

void TrafficFlow::printStatus() const {
    cout << "\n=== ÏÎÒÎÊ ÒÐÀÍÑÏÎÐÒÀ ===" << endl;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << i + 1 << ". " << vehicles[i]->getBrand() << " | ñêîðîñòü: "
            << vehicles[i]->getCurrentSpeed() << " êì/÷" << endl;
    }
}

int TrafficFlow::getVehicleCount() const {
    return vehicles.size();
}
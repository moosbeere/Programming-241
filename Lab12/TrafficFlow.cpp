#include "TrafficFlow.h"
#include <iostream>

using namespace std;

void TrafficFlow::addVehicle(std::unique_ptr<Vehicle> v) {
    vehicles.push_back(move(v));
}

void TrafficFlow::simulate(double timeStepHours, const RoadSegment& road) {
    double limit = road.getSpeedLimit();
    for (auto& v : vehicles) {
        v->update(limit, timeStepHours);
    }
}

void TrafficFlow::printStatus() const {
    cout << "\nТранспортный поток:\n";
    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << "ТС " << i + 1 << ":\n";
        vehicles[i]->getStatus();
        cout << "\n";
    }
}
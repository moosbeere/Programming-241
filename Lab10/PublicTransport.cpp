#include "PublicTransport.h"
#include <iostream>

using namespace std;

PublicTransport::PublicTransport(const std::string& brand, int maxSpeed, const std::string& route, int capacity)
    : Vehicle(brand, maxSpeed), routeNumber(route), passengerCapacity(capacity) {
}

void PublicTransport::info() {
    getStatus();
    cout << "Route: " << routeNumber << ", Capacity: " << passengerCapacity << endl;
}
#include <iostream>
#include "PublicTransport.h"
using namespace std;

PublicTransport::PublicTransport(const string& brand, int maxSpeed, const string& route, int capacity)
    : Vehicle(brand, maxSpeed), routeNumber(route), passengerCapacity(capacity) {
}

string PublicTransport::getRouteNumber() const {
    return routeNumber;
}

int PublicTransport::getPassengerCapacity() const {
    return passengerCapacity;
}
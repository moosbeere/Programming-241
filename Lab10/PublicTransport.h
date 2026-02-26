#pragma once
#include "Vehicle.h"
#include <string>

using namespace std;

class PublicTransport : virtual public Vehicle {
public:
    string routeNumber;
    int passengerCapacity;

    PublicTransport(const string& brand, int maxSpeed,
        const string& route, int capacity);
    void info();
};
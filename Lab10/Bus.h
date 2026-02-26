#pragma once
#include "PublicTransport.h"
#include "Vehicle.h"
#include <string>

using namespace std;

class Bus : public PublicTransport, virtual public Vehicle {
public:
    string fuelType;

    Bus(const string& brand, int maxSpeed,
        const string& route, int capacity, const string& fuel);
    void info();
};
#pragma once

#include "PublicTransport.h"
#include "Vehicle.h"
#include <string>

using namespace std;

class Bus : public PublicTransport, public Vehicle {
private:
    string fuelType;

public:
    Bus(string n, int s, int route, int capacity, string fuel);
    void print() const;
};
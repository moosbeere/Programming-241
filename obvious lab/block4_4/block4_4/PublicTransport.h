#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class PublicTransport : virtual public Vehicle {
protected:
    string routeNumber;
    int passengerCapacity;

public:
    PublicTransport(const string& brand, int maxSpeed, const string& route, int capacity);

    string getRouteNumber() const;
    int getPassengerCapacity() const;

    void displayInfo()const=0;
    string getType()const=0;
};

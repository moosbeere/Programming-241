#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "vehicle.h"

using namespace std;

class Route {
private:
    string startPoint;
    string endPoint;
    double length;

public:
    Route(string start, string end, double len);
    void printInfo() const;
    double getLength() const { return length; }
};

class AssignedRoute {
private:
    Route route;
    unique_ptr<TransportUnit> transportUnit; // Умный указатель

public:
    // Конструктор принимает unique_ptr
    AssignedRoute(string start, string end, double length, unique_ptr<TransportUnit> transport);

    void printFullInfo() const;
    void setTransportUnit(unique_ptr<TransportUnit> newTransport);
};

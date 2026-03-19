#pragma once
#include <string>
#include <memory>
#include "Unit.h"
using namespace std;
class Route {
public:
    string startPoint;
    string endPoint;
    int length;

    Route(string from = "", string to = "", int dist = 0);
    void printInfo() const;
};

class AssignedRoute {
private:
    Route route;
    std::unique_ptr<TransportUnit> transport;

public:
    AssignedRoute(const Route& r, unique_ptr<TransportUnit> t);

    double calculateTotalCost() const;
    void printInfo() const;
};
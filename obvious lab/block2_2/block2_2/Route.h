#pragma once
using namespace std;
#include <string>
#include <memory>  
#include "Unit.h"

class Route {
public:
    string startPoint;
    string endPoint;
    int length;

    void PrintInfo();
};

class AssignedRoute {
private:
    Route route;
    std::unique_ptr<TransportUnit> transport;

public:
    AssignedRoute(const Route& r, std::unique_ptr<TransportUnit> t);

    double calculateTotalCost() const;
    void printInfo() const;
};
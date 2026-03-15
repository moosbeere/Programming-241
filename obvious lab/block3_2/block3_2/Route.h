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
    unique_ptr<TransportUnit> transport;  
    Route* route;

public:
    AssignedRoute(unique_ptr<TransportUnit> t, Route* r);

    AssignedRoute(const AssignedRoute&) = delete;
    AssignedRoute& operator=(const AssignedRoute&) = delete;

    ~AssignedRoute();

    double calculateTotalCost();
    void PrintInfo();
};


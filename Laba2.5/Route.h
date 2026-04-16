#pragma once

#include <iostream>
#include <string>
#include "vehicle.h"

class Route 
{
private:
    std::string startPoint;
    std::string endPoint;
    double length;

public:
    Route(const std::string& start, const std::string& end, double len);
    void printInfo() const;
    double getLength() const { return length; }
};

class AssignedRoute 
{
private:
    Route route;                    // Композиция
    TransportUnit* transportUnit;   // Агрегация

public:
    AssignedRoute(const std::string& start, const std::string& end, double length, TransportUnit* transport);
    double calculateTotalCost() const;
    void printFullInfo() const;
    void setTransportUnit(TransportUnit* newTransport);
};
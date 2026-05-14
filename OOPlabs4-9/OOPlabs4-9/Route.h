#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
private:
    std::string startPoint;
    std::string endPoint;
    double length;

public:
    Route(std::string startPoint,
        std::string endPoint,
        double length);

    double getLength() const;
    void printInfo() const;
};

#endif#pragma once

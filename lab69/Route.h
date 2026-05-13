#pragma once
#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>

using namespace std;

// ======================================================
// Класс Route
// ======================================================

class Route {
private:

    string startPoint;
    string endPoint;
    double length;

public:

    Route(string start, string end, double len);

    double getLength() const;

    void printInfo() const;
};

#endif
#pragma once

#include <iostream>
#include <string>

// Класс "Маршрут" (композиция).
class Route
{
private:
    std::string startPoint;
    std::string endPoint;
    double length; // в км

public:
    Route(const std::string& startPoint,
          const std::string& endPoint,
          double length)
        : startPoint(startPoint),
          endPoint(endPoint),
          length(length < 0 ? 0.0 : length)
    {
    }

    double getLength() const
    {
        return length;
    }

    void printInfo() const
    {
        std::cout << "Route info:\n";
        std::cout << "  from: " << startPoint << "\n";
        std::cout << "  to:   " << endPoint << "\n";
        std::cout << "  length: " << length << " km\n";
    }
};


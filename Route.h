#pragma once
#include <string>

class Route {
private:
    std::string startPoint;
    std::string endPoint;
    double length;
public:
    Route(const std::string& start, const std::string& end, double len);
    void printInfo() const;

    double getLength() const { return length; }
};



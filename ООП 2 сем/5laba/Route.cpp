#include "Route.h"
#include <iostream>

Route::Route(const std::string& start, const std::string& end, double len)
    : startPoint(start), endPoint(end), length(len) {}

void Route::printInfo() const {
    std::cout << "Маршрут: " << startPoint << " -> " << endPoint
              << ", длина: " << length << " км" << std::endl;
}

double Route::getLength() const {
    return length;
}

const std::string& Route::getStartPoint() const {
    return startPoint;
}

const std::string& Route::getEndPoint() const {
    return endPoint;
}

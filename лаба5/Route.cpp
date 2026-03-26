#include "Route.h"
#include <iostream>

Route::Route(const std::string& start, const std::string& end, double len)
    : startPoint(start), endPoint(end), length(len) {}

void Route::printInfo() const {
    std::cout << "Начальная точка: " << startPoint << " -> " << endPoint
        << ", длина" << length << " êì" << std::endl;
}

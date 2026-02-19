#include "Route.h"
#include <iostream>

using namespace std;

Route::Route(const string& start, const string& end, double len)
    : startPoint(start), endPoint(end), length(len) {
}

void Route::printInfo() const {
    cout << "Начало: " << startPoint << "\nКонец: " << endPoint
        << "\nДлина: " << length << " км\n";
}

double Route::getLength() const {
    return length;
}
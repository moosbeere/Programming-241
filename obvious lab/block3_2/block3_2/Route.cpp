#include "Route.h"
#include <iostream>
using namespace std;
Route::Route(string from, string to, int dist)
    : startPoint(from), endPoint(to), length(dist) {
}

void Route::printInfo() const {
    cout << "Маршрут: " << startPoint << " " << endPoint << endl;
    cout << "Длина: " << length << " км" << endl;
}

AssignedRoute::AssignedRoute(const Route& r, unique_ptr<TransportUnit> t)
    : route(r), transport(move(t)) {
}

double AssignedRoute::calculateTotalCost() const {
    return transport->calculateToll(route.length);
}

void AssignedRoute::printInfo() const {
    cout <<endl;
    route.printInfo();
    cout << "Транспорт: " << transport->getType() << std::endl;
    cout << "Стоимость: " << calculateTotalCost() << " $" << std::endl;
}
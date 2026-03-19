#include "Route.h"
#include <iostream>

Route::Route(std::string from, std::string to, int dist)
    : startPoint(from), endPoint(to), length(dist) {
}

void Route::printInfo() const {
    std::cout << "Маршрут: " << startPoint << " " << endPoint << std::endl;
    std::cout << "Длина: " << length << " км" << std::endl;
}

AssignedRoute::AssignedRoute(const Route& r, std::unique_ptr<TransportUnit> t)
    : route(r), transport(std::move(t)) {
}

double AssignedRoute::calculateTotalCost() const {
    return transport->calculateToll(route.length);
}

void AssignedRoute::printInfo() const {
    std::cout << "\nМаршрут" << std::endl;
    route.printInfo();
    std::cout << "Транспорт: " << transport->getType() << std::endl;
    std::cout << "Стоимость: " << calculateTotalCost() << " у.е." << std::endl;
}
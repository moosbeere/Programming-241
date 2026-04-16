#include "route.h"

// Реализация Route
Route::Route(const std::string& start, const std::string& end, double len)
    : startPoint(start), endPoint(end), length(len) 
{
    if (len < 0) 
        length = 0;
}

void Route::printInfo() const {
    std::cout << "Маршрут: " << startPoint << " -> " << endPoint
        << ", длина: " << length << " км";
}

// Реализация AssignedRoute
AssignedRoute::AssignedRoute(const std::string& start, const std::string& end, double length, TransportUnit* transport)
    : route(start, end, length), transportUnit(transport) { }

double AssignedRoute::calculateTotalCost() const {
    return transportUnit->calculateToll(route.getLength());
}

void AssignedRoute::printFullInfo() const 
{
    std::cout << "\n=== Назначенный маршрут ===" << std::endl;
    route.printInfo();
    std::cout << std::endl;
    std::cout << "Транспорт: ";
    transportUnit->printInfo();
    std::cout << std::endl;
    std::cout << "Общая стоимость: " << calculateTotalCost() << " у.е." << std::endl;
    std::cout << "===========================\n" << std::endl;
}

void AssignedRoute::setTransportUnit(TransportUnit* newTransport) {
    if (newTransport) {
        transportUnit = newTransport;
    }
}
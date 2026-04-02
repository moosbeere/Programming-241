#include "AssignedRoute.h"
#include <iostream>

AssignedRoute::AssignedRoute(const std::string& start, const std::string& end, double len, TransportUnit* trans)
    : route(start, end, len), transport(trans) {
    // route создаётся через список инициализации – композиция
}

double AssignedRoute::calculateTotalCost() const {
    
    if (transport) {
        return transport->calculateToll(route.getLength());
    }
    // Если транспорт не задан, стоимость 0
    return 0.0;
}

void AssignedRoute::printInfo() const {
    std::cout << "Назначенный маршрут:" << std::endl;
    route.printInfo();
    if (transport) {
        std::cout << "Транспорт: " << transport->getName() << std::endl;
        std::cout << "Стоимость проезда: " << calculateTotalCost() << " руб." << std::endl;
    } else {
        std::cout << "Транспорт не назначен." << std::endl;
    }
}

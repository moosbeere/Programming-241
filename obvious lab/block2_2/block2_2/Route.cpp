#include "Route.h"
#include <iostream>
#include <memory>
using namespace std;

class Route {
public:
    std::string startPoint;
    std::string endPoint;
    int length;

    Route(std::string from = "", std::string to = "", int dist = 0);
    void printInfo() const;
};

AssignedRoute::AssignedRoute(const Route& r, std::unique_ptr<TransportUnit> t)
    : route(r), transport(std::move(t)) {
}

double AssignedRoute::calculateTotalCost() const {
    return transport->calculateToll(route.length);
}

void AssignedRoute::printInfo() const {
    std::cout << "\n Назначенный маршрут" << std::endl;
    route.printInfo();
    std::cout << "Стоимость проезда: " << calculateTotalCost() << " у.е." << std::endl;
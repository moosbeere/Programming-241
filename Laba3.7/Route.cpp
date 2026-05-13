#include "route.h"

Route::Route(string start, string end, double len)
    : startPoint(start), endPoint(end), length(len) {
}

void Route::printInfo() const {
    cout << "Маршрут: " << startPoint << " -> " << endPoint << ", " << length << " км";
}

AssignedRoute::AssignedRoute(string start, string end, double length, unique_ptr<TransportUnit> transport)
    : route(start, end, length), transportUnit(move(transport)) {
}

void AssignedRoute::printFullInfo() const {
    route.printInfo();
    cout << " | Транспорт: ";
    transportUnit->printInfo();
    cout << " | Стоимость: " << transportUnit->calculateToll(route.getLength()) << endl;
}

void AssignedRoute::setTransportUnit(unique_ptr<TransportUnit> newTransport) {
    transportUnit = move(newTransport); // Старый объект удалится сам
}

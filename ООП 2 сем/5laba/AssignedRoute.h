#ifndef ASSIGNEDROUTE_H
#define ASSIGNEDROUTE_H

#include "Route.h"
#include "TransportUnit.h"

class AssignedRoute {
private:
    Route route;                
    TransportUnit* transport;     // Агрегация: указатель на внешний объект

public:
    // Конструктор: инициализирует маршрут (композиция) и связывает транспорт (агрегация)
    AssignedRoute(const std::string& start, const std::string& end, double len, TransportUnit* trans);

    double calculateTotalCost() const;

    
    void printInfo() const;
};

#endif

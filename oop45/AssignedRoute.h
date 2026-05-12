#pragma once
#ifndef ASSIGNEDROUTE_H
#define ASSIGNEDROUTE_H

#include "Route.h"
#include "TransportUnit.h"


// Класс AssignedRoute


class AssignedRoute {
private:

    // Композиция
    Route route;

    // Агрегация
    TransportUnit* transport;

public:

    // Конструктор
    AssignedRoute(Route r, TransportUnit* t);

    // Расчет стоимости
    double calculateTotalCost() const;

    // Вывод информации
    void printAssignedInfo() const;
};

#endif
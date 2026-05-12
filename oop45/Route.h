#pragma once
#ifndef ROUTE_H
#define ROUTE_H

#include <string>

using namespace std;


// Класс Route


class Route {
private:

    string startPoint;
    string endPoint;
    double length;

public:

    // Конструктор
    Route(string start, string end, double len);

    // Вывод информации
    void printInfo() const;

    // Получение длины маршрута
    double getLength() const;
};

#endif
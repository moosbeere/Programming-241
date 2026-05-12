#include <iostream>
#include "Route.h"

using namespace std;


// Конструктор


Route::Route(string start, string end, double len) {

    startPoint = start;
    endPoint = end;
    length = len;
}


// Вывод информации


void Route::printInfo() const {

    cout << "Маршрут: "
        << startPoint
        << " -> "
        << endPoint
        << endl;

    cout << "Длина: "
        << length
        << " км"
        << endl;
}


// Возвращает длину маршрута


double Route::getLength() const {

    return length;
}
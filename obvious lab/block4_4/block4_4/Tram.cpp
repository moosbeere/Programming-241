#include <iostream>
#include "Tram.h"
using namespace std;

Tram::Tram(const string& brand, int maxSpeed, const string& route, int capacity, int voltage)
    :Vehicle(brand, maxSpeed), PublicTransport(brand, maxSpeed, route, capacity), electricLineVoltage(voltage) {
}

int Tram::getVoltage() const {
    return electricLineVoltage;
}

void Tram::displayInfo() const {
    cout << "Трамвай" << endl;
    getStatus();
    cout << "Маршрут: " << routeNumber << endl;
    cout << "Вместимость: " << passengerCapacity << " человек" << endl;
    cout << "Напряжение: " << electricLineVoltage << " В" << endl;
}

string Tram::getType() const {
    return "Трамвай";
}
#include "public_transport.h"
#include <iostream>
using namespace std;

PublicTransport::PublicTransport(string n, int speed, string route, int capacity)
    : Vehicle(n, speed), routeNumber(route), passengerCapacity(capacity) {
    cout << "Вызван указатель PublicTransport для маршрута: " << routeNumber << endl;
}

void PublicTransport::printInfo() const {
    Vehicle::printInfo();
    cout << " | Маршрут: №" << routeNumber << ", Вместимость: " << passengerCapacity << " чел.";
}

//Tram
Tram::Tram(string n, int speed, string route, int capacity, int voltage)
    : Vehicle(n, speed), PublicTransport(n, speed, route, capacity), electricLineVoltage(voltage) {
}

void Tram::printInfo() const {
    PublicTransport::printInfo();
    cout << " | Напряжение сети: " << electricLineVoltage << " В" << endl;
}

//Bus
Bus::Bus(string n, int speed, string route, int capacity, string fuel)
    : Vehicle(n, speed), PublicTransport(n, speed, route, capacity), fuelType(fuel) {
    cout << "Вызван конструктор Bus" <<endl;
}

void Bus::printInfo() const {
    PublicTransport::printInfo();
    cout << " | Топливо: " << fuelType << endl;
}

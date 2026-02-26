#include "Tram.h"
#include <iostream>

using namespace std;

Tram::Tram(const string& brand, int maxSpeed,
    const string& route, int capacity, int voltage)
    : Vehicle(brand, maxSpeed), PublicTransport(brand, maxSpeed, route, capacity), electricLineVoltage(voltage) {
}

void Tram::info() {
    PublicTransport::info();
    cout << "Line voltage: " << electricLineVoltage << " V" << endl;
}
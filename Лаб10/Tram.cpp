#include "Tram.h"
#include <iostream>

using namespace std;

Tram::Tram(int route, int capacity, int voltage): PublicTransport(route, capacity) {
    electricLineVoltage = voltage;
}

void Tram::print() const {
    cout << "____Трамвай____" << endl;
    printPublicTransport();
    cout << "Напряжение линии: " << electricLineVoltage << " В" << endl;
}
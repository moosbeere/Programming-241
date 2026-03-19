#include "PublicTransport.h"
#include <iostream>

using namespace std;

PublicTransport::PublicTransport(int route, int capacity) {
    routeNumber = route;
    passengerCapacity = capacity;
}

void PublicTransport::printPublicTransport() const {
    cout << "Маршрут: " << routeNumber << ", Вместимость: " << passengerCapacity << endl;
}
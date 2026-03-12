#include <iostream>
#include "Car.h"
#include "Truck.h"

using namespace std;

int main() {
    TransportUnit* units[2];

    Car car;
    Truck truck;

    units[0] = &car;
    units[1] = &truck;

    double distance = 100;

    for (int i = 0; i < 2; i++) {
        cout << units[i]->calculateToll(distance) << endl;
    }

    return 0;
}
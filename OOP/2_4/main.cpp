#include <iostream>
#include "TransportUnit.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const double distance = 100.0;

    TransportUnit* vehicles[2];

    vehicles[0] = new Car();
    vehicles[1] = new Truck();

    for (int i = 0; i < 2; i++) {
        cout << "Плата за проезд: "
             << vehicles[i]->calculateToll(distance)
             << " у.е." << endl;
    }
    return 0;
}
#include <iostream>
#include "car.h"
#include "truck.h"

using namespace std;

int main() {

    Base* list[2];

    list[0] = new Car();
    list[1] = new Truck();

    double dist = 100;

    for (int i = 0; i < 2; i++) {
        cout << list[i]->calculateToll(dist) << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete list[i];
    }

    return 0;
}
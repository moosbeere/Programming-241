#include <iostream>
#include "Vehicle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Vehicle first = Vehicle("Toyota", 200);
    Vehicle second = Vehicle("Lada", 140);

    first.getStatus();
    second.getStatus();
    first.accelerate(300);
    first.getStatus();
    first.brake(1000);
    first.getStatus();
    second.accelerate(100);
    second.brake(10);
    second.getStatus();
}
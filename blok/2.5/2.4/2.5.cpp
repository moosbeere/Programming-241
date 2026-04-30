#include <iostream>
#include "TransportUnit.h"
#include "Car.h"
#include "Truck.h"
#include "Route.h"
#include "AssignedRoute.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    Route r1("", "", 700);
    Car c1;
    AssignedRoute a(r1, &c1);
    r1.PrintInfo();
    cout << a.calculateTotalCost();
}


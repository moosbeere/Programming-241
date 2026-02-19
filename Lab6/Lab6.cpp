#include <iostream>
#include "DispatchCenter.h"
#include "Vehicle.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    DispatchCenter::report();

    Vehicle car1("Lada");
    Vehicle car2("Geely");
    Vehicle car3("BMW");

    DispatchCenter::report();
}
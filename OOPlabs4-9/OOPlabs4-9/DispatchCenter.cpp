#include <iostream>
#include "DispatchCenter.h"

int DispatchCenter::totalVehiclesDispatched = 0;

void DispatchCenter::report() {
    std::cout << "Total vehicles: "
        << totalVehiclesDispatched
        << std::endl;
}
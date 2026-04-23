#include "DispatchCenter.h"
#include <iostream>

int DispatchCenter::totalVehiclesDispatched = 0;

void DispatchCenter::report() {
    std::cout << "Всего обслужено ТС: " << totalVehiclesDispatched << std::endl;
}

#pragma once

#include <iostream>

class DispatchCenter {
public:
    
    static int totalVehiclesDispatched;

    
    static void report() {
        std::cout << "Общее количество обслуженных транспортных средств: " << totalVehiclesDispatched << std::endl;
    }

};
#pragma once

#include "DispatchCenter.h"

class Vehicle {
public:
    Vehicle() {
        
        DispatchCenter::totalVehiclesDispatched++;
    }
};
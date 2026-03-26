#include <iostream>
#include "Vehicle.h"

// обьявляем стат поле
int DispatchCenter::totalVehiclesDispatched = 0;

int main() {
    
    Vehicle v1;
    Vehicle v2;
    Vehicle v3;

   
    DispatchCenter::report();

  
    Vehicle v4;

   
    DispatchCenter::report();

    return 0;
}
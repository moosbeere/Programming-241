#include "Vehicle.h"
#include "DispatchCenter.h"
#include <iostream>
using namespace std;


Vehicle::Vehicle(string b, string m, string plate) {
    brand = b;
    model = m;
    plateNumber = plate;
    
    // При создании нового ТС увеличиваем счетчик в диспетчерской
    DispatchCenter::addVehicle();
    
    cout << "[СОЗДАНО] Транспортное средство: " 
         << brand << " " << model << " (" << plateNumber << ")" << endl;
}

void Vehicle::showInfo() const {
    cout << "Транспортное средство: " << brand << " " << model 
         << ", госномер: " << plateNumber << endl;
}

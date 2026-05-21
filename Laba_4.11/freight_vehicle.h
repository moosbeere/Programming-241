#pragma once
#include <string>
using namespace std;

class FreightVehicle {
private:
    string name;
    double cargoCapacity;

public:
    FreightVehicle(string n, double capacity);
    double getCargoCapacity() const;
    string getName() const;
};

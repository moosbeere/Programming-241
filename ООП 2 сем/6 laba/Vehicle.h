#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string model;
    std::string number;
public:
    Vehicle(const std::string& m, const std::string& n);
    void registerVehicle();   // метод, увеличивающий счётчик
};

#endif

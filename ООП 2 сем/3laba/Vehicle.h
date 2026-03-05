#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    std::string brand;          

public:
    // Конструктор с одним параметром (марка)
    Vehicle(const std::string& b) : brand(b) {}

  
    virtual void getStatus() {
        std::cout << "Марка: " << brand << std::endl;
    }
};

#endif


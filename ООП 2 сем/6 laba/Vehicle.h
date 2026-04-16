#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
private:
    string brand;    
    string model;      
    string plateNumber; // Госномер
    
public:
    Vehicle(string b, string m, string plate);
    
    // Метод для вывода информации о ТС
    void showInfo() const;
};

#endif

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string brand;   // марка автомобиля
    int maxSpeed;        // максимальная скорость
    int currentSpeed;    // текущая скорость

public:
    // Конструктор
    Vehicle(std::string b, int ms);
    
    // Методы для управления скоростью
    void accelerate(int increment);
    void brake(int decrement);
    
    // Метод для вывода информации
    void getStatus();
};

#endif

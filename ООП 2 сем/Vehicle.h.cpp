#ifndef VEHICLE_H      // Защита от повторного включения
#define VEHICLE_H

#include <iostream>
#include <string>

// Базовый класс "Транспортное средство"
class Vehicle {
private:
    std::string brand;  // Марка транспортного средства

public:
    // Конструктор с параметром для инициализации марки
    Vehicle(const std::string& b) : brand(b) {}

    // Виртуальный деструктор (нужен для корректного удаления через указатель на базовый класс)
    virtual ~Vehicle() {}

    // Виртуальный метод для получения статуса (будет переопределён в наследниках)
    virtual void getStatus() const {
        std::cout << "Марка: " << brand << std::endl;
    }

    // Метод доступа к марке (если понадобится в наследниках)
    std::string getBrand() const { return brand; }
};

#endif
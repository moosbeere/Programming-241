#include "FreightVehicle.h"

FreightVehicle::FreightVehicle(const std::string& b, double capacity)
    : Vehicle(b),               // вызываем конструктор базового класса
      cargoCapacity(capacity)    // инициализируем своё поле
{}

// Реализация переопределённого метода getStatus()
void FreightVehicle::getStatus() {
    Vehicle::getStatus();        // вызываем метод базового класса (выводит марку)
    std::cout << "Грузоподъёмность: " << cargoCapacity << " тонн" << std::endl;
}

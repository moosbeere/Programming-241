#include "FreightVehicle.h"

// Реализация конструктора
FreightVehicle::FreightVehicle(const std::string& b, double capacity)
    : Vehicle(b),            // вызываем конструктор базового класса с маркой
      cargoCapacity(capacity) // инициализируем собственное поле
{}

// Переопределённый метод getStatus()
void FreightVehicle::getStatus() const {
    // Сначала можно вызвать базовую версию, чтобы вывести марку
    Vehicle::getStatus();  // выводит "Марка: ..."
    // Затем добавляем информацию о грузоподъёмности
    std::cout << "Грузоподъёмность: " << cargoCapacity << " тонн" << std::endl;
}
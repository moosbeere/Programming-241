#ifndef FREIGHTVEHICLE_H
#define FREIGHTVEHICLE_H

#include "Vehicle.h"   // Подключаем базовый класс

// Производный класс "Грузовой транспорт"
class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;  // Грузоподъёмность в тоннах (private)

public:
    // Конструктор: передаём марку в базовый класс и инициализируем своё поле
    FreightVehicle(const std::string& b, double capacity);

    // Переопределённый метод getStatus() — теперь выводит и грузоподъёмность
    void getStatus() const override;
};

#endif
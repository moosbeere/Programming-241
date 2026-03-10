#include <iostream>
#include <string>

#include "vehicle.h"

// Класс "Грузовой транспорт", наследуется от Vehicle
class FreightVehicle : public Vehicle
{
private:
    double cargoCapacity; // грузоподъёмность в тоннах

public:
    // Конструктор: инициализируем базовый класс и новое поле
    FreightVehicle(const std::string& brand, int maxSpeed, double cargoCapacity)
        : Vehicle(brand, maxSpeed),
          cargoCapacity(cargoCapacity < 0 ? 0.0 : cargoCapacity)
    {
    }

    // Переопределённый (расширенный) метод getStatus:
    // сначала выводит информацию базового класса, затем грузоподъёмность
    void getStatus() const override
    {
        Vehicle::getStatus();
        std::cout << "  cargoCapacity: " << cargoCapacity << " tons\n";
        std::cout << "\n";
    }
};

int main()
{
    // Примеры использования грузового транспорта
    FreightVehicle truck1("Volvo", 120, 20.5);
    FreightVehicle truck2("MAN", 110, 15.0);

    std::cout << "=== Initial status ===\n";
    truck1.getStatus();
    truck2.getStatus();

    // Немного "едем": ускоряем и тормозим
    truck1.accelerate(60);
    truck2.accelerate(80);
    truck2.brake(30);

    std::cout << "=== After movement ===\n";
    truck1.getStatus();
    truck2.getStatus();

    return 0;
}

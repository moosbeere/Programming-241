#include <iostream>
#include <string>

// Базовый класс "Транспортное средство" (как в лабе 2)
class Vehicle
{
private:
    std::string brand;   // марка транспортного средства
    int maxSpeed;        // максимальная возможная скорость
    int currentSpeed;    // текущая скорость (меняется при ускорении/торможении)

public:
    Vehicle(const std::string& brand, int maxSpeed)
        : brand(brand),
          maxSpeed(maxSpeed < 0 ? 0 : maxSpeed),
          currentSpeed(0)
    {
    }

    void accelerate(int increment)
    {
        if (increment <= 0)
            return;

        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    void brake(int decrement)
    {
        if (decrement <= 0)
            return;

        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    void getStatus() const
    {
        std::cout << "Vehicle status:\n";
        std::cout << "  brand: " << brand << "\n";
        std::cout << "  maxSpeed: " << maxSpeed << "\n";
        std::cout << "  currentSpeed: " << currentSpeed << "\n";
    }
};

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
    void getStatus() const
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

#include <iostream>
#include <string>
#include <vector>

// Класс "Транспортное средство"
class Vehicle
{
private:
    std::string brand;   // марка транспортного средства
    int maxSpeed;        // максимальная возможная скорость
    int currentSpeed;    // текущая скорость (меняется при ускорении/торможении)

public:
    // Конструктор: задаём марку и максимальную скорость, текущая скорость всегда стартует с 0
    Vehicle(const std::string& brand, int maxSpeed)
        : brand(brand),
          maxSpeed(maxSpeed < 0 ? 0 : maxSpeed), // защита от отрицательной maxSpeed
          currentSpeed(0)                        // по условию currentSpeed = 0 при создании
    {
    }

    // Ускорение: увеличиваем currentSpeed на increment, но не превышаем maxSpeed
    void accelerate(int increment)
    {
        // Если increment некорректный (0 или отрицательный) — ничего не делаем
        if (increment <= 0)
            return;

        // Увеличиваем текущую скорость
        currentSpeed += increment;
        // Ограничиваем сверху максимальной скоростью
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    // Торможение: уменьшаем currentSpeed на decrement, но не уходим ниже 0
    void brake(int decrement)
    {
        // Если decrement некорректный (0 или отрицательный) — ничего не делаем
        if (decrement <= 0)
            return;

        // Уменьшаем текущую скорость
        currentSpeed -= decrement;
        // Ограничиваем снизу нулём
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // Выводим в консоль информацию о транспортном средстве (все поля)
    void getStatus() const
    {
        std::cout << "Vehicle status:\n";
        std::cout << "  brand: " << brand << "\n";
        std::cout << "  maxSpeed: " << maxSpeed << "\n";
        std::cout << "  currentSpeed: " << currentSpeed << "\n";
        std::cout << "\n"; 
    }
};

int main()
{
    // Массив из 5 различных транспортных средств
    std::vector<Vehicle> vehicles = {
        Vehicle("Toyota", 180),
        Vehicle("BMW", 250),
        Vehicle("Lada", 140),
        Vehicle("Mercedes", 220),
        Vehicle("Volkswagen", 200)
    };

    // Симмулируем движение: ускоряем каждое с разными значениями
    vehicles[0].accelerate(80);
    vehicles[1].accelerate(120);
    vehicles[2].accelerate(60);
    vehicles[3].accelerate(200);
    vehicles[4].accelerate(150);

    // Для некоторых — торможение
    vehicles[0].brake(30);
    vehicles[2].brake(40);
    vehicles[4].brake(50);

    // В конце выводим статус всех транспортных средств
    std::cout << "=== Итоговый статус всех транспортных средств ===\n\n";
    for (size_t i = 0; i < vehicles.size(); ++i)
    {
        vehicles[i].getStatus();
    }

    return 0;
}
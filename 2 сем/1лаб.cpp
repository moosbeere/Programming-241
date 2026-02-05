#include <iostream>
#include <string>

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
    // Создаём объект: марка "Toyota", максимальная скорость 180
    Vehicle car("Toyota", 180);
    // Смотрим начальное состояние (скорость должна быть 0)
    car.getStatus();

    // Ускоряемся на 50
    car.accelerate(50);
    car.getStatus();

    // Пытаемся ускориться слишком сильно: скорость не должна превысить maxSpeed (180)
    car.accelerate(200);
    car.getStatus();

    // Тормозим на 30
    car.brake(30);
    car.getStatus();

    // Пытаемся затормозить слишком сильно: скорость не должна уйти ниже 0
    car.brake(999);
    car.getStatus();

    return 0;
}
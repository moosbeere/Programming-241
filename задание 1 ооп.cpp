#include <iostream>
#include <iostream>
#include <string>
#include <clocale>   // для setlocale

class Vehicle {
private:
    std::string brand;
    int maxSpeed;
    int currentSpeed;

public:
    // Конструктор
    Vehicle(const std::string& b, int ms)
        : brand(b), maxSpeed(ms), currentSpeed(0) {
    }

    // Увеличение скорости
    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    // Уменьшение скорости
    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // Вывод состояния (все поля) на русском языке
    void getStatus() const {
        std::cout << "Марка: " << brand
            << ", Макс. скорость: " << maxSpeed
            << ", Текущая скорость: " << currentSpeed
            << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Vehicle car("Toyota", 180);
    car.getStatus();   // Марка: Toyota, Макс. скорость: 180, Текущая скорость: 0

    car.accelerate(50);
    car.getStatus();   // Текущая скорость: 50

    car.accelerate(150); // ограничение максимальной скоростью
    car.getStatus();   // Текущая скорость: 180

    car.brake(30);
    car.getStatus();   // Текущая скорость: 150

    car.brake(200);    // ограничение нулём
    car.getStatus();   // Текущая скорость: 0

    return 0;
}
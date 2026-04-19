#pragma once

#include <string>

// Класс "Транспортное средство"
class Vehicle
{
private:
    std::string brand;   // марка транспортного средства
    int maxSpeed;        // максимальная возможная скорость
    int currentSpeed;    // текущая скорость

public:
    // Конструктор для задания базовых характеристик.
    Vehicle(const std::string& brand, int maxSpeed);

    // Действия меняющие состояние объекта.
    void accelerate(int increment);
    void brake(int decrement);

    // Виртуальный метод: позволяет переопределять вывод информации в наследниках.
    virtual void getStatus() const;

    // Геттеры используются в других частях ЛР 12 (например TrafficFlow).
    int getMaxSpeed() const;
    const std::string& getBrand() const;

    // Сравнение транспортных средств по максимальной скорости
    bool operator<(const Vehicle& other) const;

    virtual ~Vehicle() = default;
};


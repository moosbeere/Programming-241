#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

/**
 * Класс "Транспортное средство"
 */
class Vehicle {
private:
    std::string brand;      // марка (приватное поле)
    int maxSpeed;           // максимальная скорость (приватное поле)
    int currentSpeed;       // текущая скорость (приватное поле)

public:
    /**
     * Конструктор с параметрами.
     * brand марка
     * maxSpeed максимальная скорость
     */
    Vehicle(const std::string& brand, int maxSpeed);

    /**
     * Увеличить текущую скорость на increment (но не выше maxSpeed).
     *  increment величина увеличения
     */
    void accelerate(int increment);

    /**
     * Уменьшить текущую скорость на decrement (но не ниже 0).
     *  decrement величина уменьшения
     */
    void brake(int decrement);

    /**
     * Вывести информацию о транспортном средстве.
     */
    void getStatus() const;
};

#endif // VEHICLE_H


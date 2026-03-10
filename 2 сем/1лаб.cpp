#include <iostream>

#include "vehicle.h"

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
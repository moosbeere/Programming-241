#include "Car.h"


// Расчет стоимости для автомобиля


double Car::calculateToll(double distance) const {

    // 0.1 у.е. за км
    return distance * 0.1;
}
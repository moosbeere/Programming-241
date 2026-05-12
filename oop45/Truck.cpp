#include "Truck.h"


// Расчет стоимости для грузовика


double Truck::calculateToll(double distance) const {

    // 0.3 у.е. за км + 5 у.е.
    return distance * 0.3 + 5.0;
}
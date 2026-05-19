#include "logisticsorder.h"
#include "freightvehicle.h"

#include <stdexcept>
#include <iostream>

LogisticsOrder::LogisticsOrder(double w)
{
    weight = w;
}

void LogisticsOrder::assignVehicle(Vehicle& v)
{
    if (weight < 0)
    {
        throw std::invalid_argument(
            "Вес не может быть отрицательным!");
    }

    FreightVehicle* fv =
        dynamic_cast<FreightVehicle*>(&v);

    if (fv)
    {
        if (weight > fv->getCargoCapacity())
        {
            throw std::invalid_argument(
                "Превышена грузоподъемность!");
        }

        std::cout << "Заказ успешно назначен"
            << std::endl;
    }
    else
    {
        throw std::invalid_argument(
            "Транспорт не является грузовым!");
    }
}
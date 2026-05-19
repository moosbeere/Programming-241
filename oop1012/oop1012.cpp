#include <iostream>
#include <memory>

#include <windows.h>
#include <locale.h>

#include "bus.h"
#include "tram.h"
#include "freightvehicle.h"
#include "logisticsorder.h"
#include "trafficflow.h"
#include "car.h"

int main()
{
    // настройка русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");


    // ЗАДАНИЕ 10
    // Иерархия транспорта


    Bus bus(
        "MAN",
        90,
        12,
        50,
        "Дизель");

    Tram tram(
        7,
        120,
        600);

    std::cout
        << "Общественный транспорт"
        << std::endl;

    bus.info();

    tram.info();

    std::cout << std::endl;


    // ЗАДАНИЕ 11
    // Исключения


    FreightVehicle truck(
        "Грузовик",
        80,
        5000);

    LogisticsOrder order1(3000);

    LogisticsOrder order2(7000);

    try
    {
        order1.assignVehicle(truck);

        order2.assignVehicle(truck);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout
            << "Исключение: "
            << e.what()
            << std::endl;
    }

    std::cout << std::endl;


    // ЗАДАНИЕ 12
    // Транспортный поток


    RoadSegment road(
        1000,
        60);

    TrafficFlow flow(road);

    flow.addVehicle(
        std::make_unique<Car>(
            "BMW",
            180));

    flow.addVehicle(
        std::make_unique<FreightVehicle>(
            "Большой грузовик",
            100,
            8000));

    std::cout
        << "Симуляция движения"
        << std::endl;

    flow.simulate(1.0);

    return 0;
}
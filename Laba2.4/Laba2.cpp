/*Задание 4: "Система взимания платы" (Виртуальные функции)
Создайте базовый абстрактный класс TransportUnit (Транспортная единица).
• Объявите чистую виртуальную функцию: virtual double calculateToll(double distance) const = 0; (расчет платы за проезд).
Создайте два производных класса:
• Car: плата = distance * 0.1 (0.1 у.е. за км).
• Truck: плата = distance * 0.3 + 5.0 (0.3 за км + фиксированный сбор).
В функции main() создайте массив указателей типа TransportUnit* на объекты Car и Truck. В цикле вызовите calculateToll() для каждого, передав, например, 100 км.
• Цель: Освоить абстрактные классы, виртуальные функции и полиморфизм.*/
#include<iostream>
#include<vector>
#include "vehicle.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    vector<TransportUnit*> transportUnits;

    transportUnits.push_back(new Car());
    transportUnits.push_back(new Truck());
    transportUnits.push_back(new Car());
    transportUnits.push_back(new Truck());
    transportUnits.push_back(new Car());


    double distance = 100.0;

    cout << "Расчет платы за проезд для расстояния " << distance << " км:\n";
    cout << "----------------------------------------\n";

    // Проходим по вектору и вызываем calculateToll для каждого объекта
    for (size_t i = 0; i < transportUnits.size(); ++i) 
    {
        double toll = transportUnits[i]->calculateToll(distance);

        // Чтобы определить тип, используем dynamic_cast
        if (dynamic_cast<Car*>(transportUnits[i])) 
        {
            cout << i + 1 << ". Car: " << toll << " у.е.\n";
        }
        else if (dynamic_cast<Truck*>(transportUnits[i])) 
        {
            cout << i + 1 << ". Truck: " << toll << " у.е.\n";
        }
    }

    // Освобождаем память
    for (TransportUnit* unit : transportUnits) 
    {
        delete unit;
    }

    return 0;
}


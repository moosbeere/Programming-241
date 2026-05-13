#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

#include "DispatchCenter.h"

using namespace std;

// ======================================================
// Базовый класс Vehicle
// ======================================================

class Vehicle {
protected:

    string name;
    int maxSpeed;

public:

    // Конструктор
    Vehicle(string n, int speed);

    // Виртуальная функция
    virtual double calculateToll(double distance) const = 0;

    // Вывод информации
    void printInfo() const;

    // Перегрузка <
    bool operator<(const Vehicle& other) const;

    // Виртуальный деструктор
    virtual ~Vehicle() {}
};

#endif
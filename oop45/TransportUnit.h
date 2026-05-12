#pragma once
#ifndef TRANSPORTUNIT_H
#define TRANSPORTUNIT_H


// Абстрактный базовый класс TransportUnit


class TransportUnit {
public:

    // Чистая виртуальная функция
    virtual double calculateToll(double distance) const = 0;

    // Виртуальный деструктор
    virtual ~TransportUnit() {}
};

#endif
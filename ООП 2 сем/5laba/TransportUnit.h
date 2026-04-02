#ifndef TRANSPORTUNIT_H
#define TRANSPORTUNIT_H

#include <string>


class TransportUnit {
public:
    virtual ~TransportUnit() = default;

    // Полиморфный метод расчёта платы за проезд по дистанции
    virtual double calculateToll(double distance) const = 0;

    virtual std::string getName() const = 0;
};

class Bus : public TransportUnit {
public:
    double calculateToll(double distance) const override;
    std::string getName() const override;
};

#endif

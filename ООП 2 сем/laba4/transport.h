#ifndef TRANSPORT_H  
#define TRANSPORT_H

class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0;

   
    virtual ~TransportUnit() {}
};

class Car : public TransportUnit {
public:
    // Переопределяем чисто виртуальную функцию
    // Плата = distance * 0.1
    double calculateToll(double distance) const override;
};

class Truck : public TransportUnit {
public:
    // Переопределяем чисто виртуальную функцию
    // Плата = distance * 0.3 + 5.0
    double calculateToll(double distance) const override;
};

#endif // TRANSPORT_H

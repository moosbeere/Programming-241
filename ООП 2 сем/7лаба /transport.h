#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <memory>

// Базовый класс
class TransportUnit {
protected:
    std::string model;
    double fuelRate;     // расход топлива
    int capacity;        // грузоподъемность
    
public:
    TransportUnit(std::string m, double fuel, int cap);
    virtual ~TransportUnit();
    
    virtual void show() const;
    virtual double getCost(double dist, double price) const;
    
    int getCapacity() const { return capacity; }
    std::string getModel() const { return model; }
};

// Грузовик
class Truck : public TransportUnit {
private:
    int trailerCap;
    
public:
    Truck(std::string m, double fuel, int cap, int trailer);
    
    void show() const override;
    double getCost(double dist, double price) const override;
    int getFullCap() const { return capacity + trailerCap; }
};

// Легковая машина
class Car : public TransportUnit {
private:
    std::string type;
    
public:
    Car(std::string m, double fuel, int cap, std::string t);
    
    void show() const override;
};

// Маршрут с умным указателем
class AssignedRoute {
private:
    std::string name;
    double distance;
    double weight;
    std::unique_ptr<TransportUnit> vehicle;  // умный указатель
    
public:
    AssignedRoute(std::string n, double dist, double w, 
                  std::unique_ptr<TransportUnit> v);
    
    // Запрещаем копирование
    AssignedRoute(const AssignedRoute&) = delete;
    AssignedRoute& operator=(const AssignedRoute&) = delete;
    
    // Разрешаем перемещение
    AssignedRoute(AssignedRoute&& other) = default;
    AssignedRoute& operator=(AssignedRoute&& other) = default;
    
    void showRoute() const;
    bool checkCapacity() const;
};

#endif
    
    

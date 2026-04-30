#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <memory>  // для std::unique_ptr

// Базовый класс транспортного средства
class TransportUnit {
protected:
    std::string model;
    double fuelConsumption;  // л/км
    int capacity;            // грузоподъемность в кг

public:
    TransportUnit(const std::string& m, double fuel, int cap);
    virtual ~TransportUnit();

    virtual void displayInfo() const;
    virtual double calculateFuelCost(double distance, double fuelPrice) const;
    
    // Геттеры
    std::string getModel() const { return model; }
    double getFuelConsumption() const { return fuelConsumption; }
    int getCapacity() const { return capacity; }
};

// Класс грузовика
class Truck : public TransportUnit {
private:
    int trailerCapacity;  // грузоподъемность прицепа

public:
    Truck(const std::string& m, double fuel, int cap, int trailer);
    
    void displayInfo() const override;
    double calculateFuelCost(double distance, double fuelPrice) const override;
    int getTotalCapacity() const { return capacity + trailerCapacity; }
};

// Класс легкового автомобиля
class Car : public TransportUnit {
private:
    std::string bodyType;  // тип кузова

public:
    Car(const std::string& m, double fuel, int cap, const std::string& body);
    
    void displayInfo() const override;
};

// Класс назначенного маршрута (с умным указателем)
class AssignedRoute {
private:
    std::string routeName;
    double distance;      // км
    double cargoWeight;   // кг
    std::unique_ptr<TransportUnit> transport;  // УМНЫЙ УКАЗАТЕЛЬ

public:
    // Конструктор принимает владение через unique_ptr
    AssignedRoute(const std::string& name, double dist, double cargo,
                  std::unique_ptr<TransportUnit> unit);
    
    // Запрещаем копирование (unique_ptr нельзя копировать)
    AssignedRoute(const AssignedRoute&) = delete;
    AssignedRoute& operator=(const AssignedRoute&) = delete;
    
    // Разрешаем перемещение
    AssignedRoute(AssignedRoute&& other) noexcept = default;
    AssignedRoute& operator=(AssignedRoute&& other) noexcept = default;
    
    // Деструктор не нужен - unique_ptr сам всё удалит
    
    bool canTransport() const;
    void displayRouteInfo() const;
    
    // Получить указатель на транспорт (только для чтения)
    const TransportUnit* getTransport() const { return transport.get(); }
};

#endif

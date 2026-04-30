#include "transport.h"

// === TransportUnit ===
TransportUnit::TransportUnit(std::string m, double fuel, int cap)
    : model(m), fuelRate(fuel), capacity(cap) {
    std::cout << "Создан " << model << std::endl;
}

TransportUnit::~TransportUnit() {
    std::cout << "Уничтожен " << model << std::endl;
}

void TransportUnit::show() const {
    std::cout << model << " (расход: " << fuelRate << " л/км, груз: " << capacity << " кг)";
}

double TransportUnit::getCost(double dist, double price) const {
    return dist * fuelRate * price;
}

// === Truck ===
Truck::Truck(std::string m, double fuel, int cap, int trailer)
    : TransportUnit(m, fuel, cap), trailerCap(trailer) {
    std::cout << "  + прицеп (" << trailerCap << " кг)" << std::endl;
}

void Truck::show() const {
    TransportUnit::show();
    std::cout << " + прицеп " << trailerCap << " кг (всего: " << getFullCap() << " кг)";
}

double Truck::getCost(double dist, double price) const {
    double extra = (trailerCap > 0) ? 1.2 : 1.0;
    return dist * fuelRate * price * extra;
}

// === Car ===
Car::Car(std::string m, double fuel, int cap, std::string t)
    : TransportUnit(m, fuel, cap), type(t) {
    std::cout << "  (кузов: " << type << ")" << std::endl;
}

void Car::show() const {
    TransportUnit::show();
    std::cout << ", тип: " << type;
}

// === AssignedRoute ===
AssignedRoute::AssignedRoute(std::string n, double dist, double w,
                             std::unique_ptr<TransportUnit> v)
    : name(n), distance(dist), weight(w), vehicle(std::move(v)) {
    std::cout << "Маршрут: " << name << std::endl;
}

bool AssignedRoute::checkCapacity() const {
    if (!vehicle) return false;
    
    // Проверяем, грузовик ли это
    Truck* truck = dynamic_cast<Truck*>(vehicle.get());
    if (truck) {
        return weight <= truck->getFullCap();
    }
    return weight <= vehicle->getCapacity();
}

void AssignedRoute::showRoute() const {
    std::cout << "\nМаршрут: " << name << " (" << distance << " км, груз " << weight << " кг)" << std::endl;
    
    if (!vehicle) {
        std::cout << "Машина не назначена!" << std::endl;
        return;
    }
    
    std::cout << "Транспорт: ";
    vehicle->show();
    std::cout << std::endl;
    
    if (checkCapacity()) {
        std::cout << "OK: Машина подходит" << std::endl;
        double price = 2.5;
        std::cout << "Топливо: " << vehicle->getCost(distance, price) << " руб" << std::endl;
    } else {
        std::cout << "ОШИБКА: Не хватает грузоподъемности!" << std::endl;
    }
}

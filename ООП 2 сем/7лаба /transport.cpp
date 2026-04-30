#include "transport.h"

TransportUnit::TransportUnit(const std::string& m, double fuel, int cap)
    : model(m), fuelConsumption(fuel), capacity(cap) {
    std::cout << "Создан транспорт: " << model << std::endl;
}

TransportUnit::~TransportUnit() {
    std::cout << "Уничтожен транспорт: " << model << std::endl;
}

void TransportUnit::displayInfo() const {
    std::cout << "Модель: " << model 
              << ", Расход: " << fuelConsumption << " л/км"
              << ", Грузоподъемность: " << capacity << " кг";
}

double TransportUnit::calculateFuelCost(double distance, double fuelPrice) const {
    return distance * fuelConsumption * fuelPrice;
}


Truck::Truck(const std::string& m, double fuel, int cap, int trailer)
    : TransportUnit(m, fuel, cap), trailerCapacity(trailer) {
    std::cout << "  (грузовик с прицепом +" << trailer << " кг)" << std::endl;
}

void Truck::displayInfo() const {
    TransportUnit::displayInfo();
    std::cout << ", Прицеп: +" << trailerCapacity << " кг"
              << ", ИТОГО: " << getTotalCapacity() << " кг";
}

double Truck::calculateFuelCost(double distance, double fuelPrice) const {

    double extraConsumption = (trailerCapacity > 0) ? 1.2 : 1.0;
    return distance * fuelConsumption * fuelPrice * extraConsumption;
}


Car::Car(const std::string& m, double fuel, int cap, const std::string& body)
    : TransportUnit(m, fuel, cap), bodyType(body) {
    std::cout << "  (легковой автомобиль, кузов: " << body << ")" << std::endl;
}

void Car::displayInfo() const {
    TransportUnit::displayInfo();
    std::cout << ", Тип кузова: " << bodyType;
}


AssignedRoute::AssignedRoute(const std::string& name, double dist, double cargo,
                             std::unique_ptr<TransportUnit> unit)
    : routeName(name), distance(dist), cargoWeight(cargo),
      transport(std::move(unit)) {  // ПЕРЕДАЕМ ВЛАДЕНИЕ
    std::cout << "Создан маршрут: " << routeName << std::endl;
}

bool AssignedRoute::canTransport() const {
    if (!transport) return false;
    
    // Проверяем, грузовик ли это (с прицепом)
    Truck* truck = dynamic_cast<Truck*>(transport.get());
    if (truck) {
        return cargoWeight <= truck->getTotalCapacity();
    }
    
    // Для обычного транспорта
    return cargoWeight <= transport->getCapacity();
}

void AssignedRoute::displayRouteInfo() const {
    std::cout << "\nМАРШРУТ: " << routeName << " =" << std::endl;
    std::cout << "Расстояние: " << distance << " км" << std::endl;
    std::cout << "Вес груза: " << cargoWeight << " кг" << std::endl;
    
    if (transport) {
        std::cout << "Транспортное средство: ";
        transport->displayInfo();
        std::cout << std::endl;
        
        if (canTransport()) {
            std::cout << "Статус: ТРАНСПОРТ ПОДХОДИТ" << std::endl;
            double fuelPrice = 2.5;  // цена за литр
            double cost = transport->calculateFuelCost(distance, fuelPrice);
            std::cout << "Затраты на топливо: " << cost << " руб." << std::endl;
        } else {
            std::cout << "Статус: ТРАНСПОРТ НЕ ПОДХОДИТ (мала грузоподъемность)" << std::endl;
        }
    } else {
        std::cout << "Транспорт: НЕ НАЗНАЧЕН" << std::endl;
    }
    std::cout << std::endl;
}

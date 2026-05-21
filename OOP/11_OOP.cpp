#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Базовый класс транспорта
class Vehicle {
protected:
    string model;

public:
    Vehicle(string m) : model(m) {}
};

// Грузовой транспорт
class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;

public:
    FreightVehicle(string m, double capacity) : Vehicle(m), cargoCapacity(capacity) {}

    double getCargoCapacity() const {
        return cargoCapacity;
    }
};

// Логистический заказ
class LogisticsOrder {
private:
    double weight;

public:
    LogisticsOrder(double w) : weight(w) {
        // Проверка отрицательного веса
        if (weight < 0) {
            throw invalid_argument("Вес заказа не может быть отрицательным");
        }
    }

    void assignVehicle(FreightVehicle& v) {
        // Проверка грузоподъемности
        if (weight > v.getCargoCapacity()) {
            throw invalid_argument("Вес превышает грузоподъемность транспорта");
        }

        cout << "Заказ успешно назначен транспорту" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    try {
        FreightVehicle truck("Volvo", 5000);
        LogisticsOrder order(6000);
        order.assignVehicle(truck);
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
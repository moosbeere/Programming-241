#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

// Базовый класс
class Vehicle {
protected:              // protected — доступно наследникам
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(string b, int mSpeed) {
        brand = b;
        maxSpeed = mSpeed;
        currentSpeed = 0;
    }

    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // virtual — позволяет переопределять метод в наследниках
    virtual void getStatus() {
        cout << "Марка: " << brand
            << " | Макс: " << maxSpeed
            << " | Текущая: " << currentSpeed;
    }
};

// Производный класс
class FreightVehicle : public Vehicle {
private:
    double cargoCapacity; // грузоподъемность

public:
    // Конструктор наследника
    FreightVehicle(string b, int mSpeed, double capacity)
        : Vehicle(b, mSpeed)   // вызываем конструктор родителя
    {
        cargoCapacity = capacity;
    }

    // Переопределение метода
    void getStatus() override {
        Vehicle::getStatus(); // вызываем версию родителя
        cout << " | Грузоподъемность: " << cargoCapacity << " т";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Обычная машина
    Vehicle car("Toyota", 180);

    // Грузовик
    FreightVehicle truck("Volvo Truck", 120, 15.5);

    car.accelerate(80);
    truck.accelerate(90);

    cout << "Легковая:\n";
    car.getStatus();

    cout << "\n\nГрузовая:\n";
    truck.getStatus();

    return 0;
}

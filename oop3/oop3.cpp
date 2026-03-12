#include <iostream>
#include <string>
#include <locale>
using namespace std;

// Базовый класс — транспорт
class Vehicle {
protected:              // доступно наследникам
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    // Конструктор базового класса
    Vehicle(string b, int mSpeed) {
        brand = b;
        maxSpeed = mSpeed;
        currentSpeed = 0;
    }

    // Ускорение
    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    // Торможение
    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // virtual — можно переопределять в наследниках
    virtual void getStatus() {
        cout << "Марка: " << brand
            << " | Макс: " << maxSpeed
            << " | Текущая: " << currentSpeed;
    }
};

// Производный класс — грузовой транспорт
class FreightVehicle : public Vehicle {
private:
    double cargoCapacity; // грузоподъемность

public:
    // Конструктор наследника
    FreightVehicle(string b, int mSpeed, double capacity)
        : Vehicle(b, mSpeed) // вызов конструктора родителя
    {
        cargoCapacity = capacity;
    }

    // Переопределённый метод вывода
    void getStatus() override {
        Vehicle::getStatus(); // вызываем метод базового класса
        cout << " | Грузоподъемность: " << cargoCapacity << " т";
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // русский язык

    // Создаем обычный транспорт
    Vehicle car("Toyota", 180);

    // Создаем грузовой транспорт
    FreightVehicle truck("Volvo Truck", 120, 15.5);

    // Разгон
    car.accelerate(80);
    truck.accelerate(90);

    cout << "Легковая машина:\n";
    car.getStatus();

    cout << "\n\nГрузовик:\n";
    truck.getStatus();

    return 0;
}

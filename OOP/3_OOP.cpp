#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    // Конструктор
    Vehicle(string b, int mSpeed) {
        brand = b;
        maxSpeed = mSpeed;
        currentSpeed = 0;
    }

    // Увеличение скорости
    void accelerate(int increment) {
        currentSpeed += increment;

        if (currentSpeed > maxSpeed) {
            currentSpeed = maxSpeed;
        }
    }

    // Уменьшение скорости
    void brake(int decrement) {
        currentSpeed -= decrement;

        if (currentSpeed < 0) {
            currentSpeed = 0;
        }
    }

    // Вывод информации
    virtual void getStatus() {
        cout << "Марка: " << brand << endl;
        cout << "Максимальная скорость: " << maxSpeed << " км/ч" << endl;
        cout << "Текущая скорость: " << currentSpeed << " км/ч" << endl;
    }

protected:
    // Методы доступа для наследников
    string getBrand() {
        return brand;
    }

    int getMaxSpeed() {
        return maxSpeed;
    }

    int getCurrentSpeed() {
        return currentSpeed;
    }
};

// класс - наследник
class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;

public:
    // Конструктор
    FreightVehicle(string b, int mSpeed, double capacity) : Vehicle(b, mSpeed) {
        cargoCapacity = capacity;
    }

    // Переопределение метода
    void getStatus() override {
        cout << "Грузовой транспорт:" << endl;
        cout << "Марка: " << getBrand() << endl;
        cout << "Максимальная скорость: " << getMaxSpeed() << " км/ч" << endl;
        cout << "Текущая скорость: " << getCurrentSpeed() << " км/ч" << endl;
        cout << "Грузоподъемность: " << cargoCapacity << " тонн" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    FreightVehicle truck("Volvo", 140, 18.5);

    truck.accelerate(90);
    truck.getStatus();

    return 0;
}

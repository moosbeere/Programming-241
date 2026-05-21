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
    void getStatus() {
        cout << "Марка: " << brand << endl;
        cout << "Максимальная скорость: " << maxSpeed << endl;
        cout << "Текущая скорость: " << currentSpeed << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Vehicle vehicles[5] = {
        Vehicle("Toyota", 220),
        Vehicle("BMW", 250),
        Vehicle("Audi", 240),
        Vehicle("Tesla", 260),
        Vehicle("Ford", 200)
    };

    // Ускорение
    vehicles[0].accelerate(120);
    vehicles[1].accelerate(180);
    vehicles[2].accelerate(150);
    vehicles[3].accelerate(300);
    vehicles[4].accelerate(350);

    // Замедление
    vehicles[1].brake(50);
    vehicles[3].brake(100);

    // Вывод информации 
    cout << "Статус всех транспортных средств:\n" << endl;
    for (int i = 0; i < 5; i++) {
        vehicles[i].getStatus();
    }

    return 0;
}
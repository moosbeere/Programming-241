#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

// Класс транспортного средства
class Vehicle {
private:
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

    void getStatus() {
        cout << "Марка: " << brand
            << " | Макс: " << maxSpeed
            << " | Текущая: " << currentSpeed << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Массив объектов (vector)
    vector<Vehicle> garage = {
        Vehicle("Toyota", 180),
        Vehicle("BMW", 240),
        Vehicle("Ford", 200),
        Vehicle("Lada", 160)
    };

    // Разгон всех машин
    garage[0].accelerate(50);
    garage[1].accelerate(120);
    garage[2].accelerate(90);
    garage[3].accelerate(200); // ограничится maxSpeed

    // Торможение некоторых
    garage[1].brake(40);
    garage[3].brake(70);

    cout << "Состояние транспорта:\n\n";

    // Вывод статуса всех машин
    for (Vehicle& v : garage) {
        v.getStatus();
    }

    return 0;
}

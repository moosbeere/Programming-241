#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

// Класс транспортного средства
class Vehicle {
private:
    string brand;     // марка
    int maxSpeed;     // максимальная скорость
    int currentSpeed; // текущая скорость

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
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    // Торможение
    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // Вывод состояния
    void getStatus() {
        cout << "Марка: " << brand
            << " | Макс: " << maxSpeed
            << " | Текущая: " << currentSpeed << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // включаем русский язык

    // Создаем вектор объектов транспорта
    vector<Vehicle> garage = {
        Vehicle("Toyota", 180),
        Vehicle("BMW", 240),
        Vehicle("Ford", 200),
        Vehicle("Lada", 160)
    };

    // Разгон каждой машины
    garage[0].accelerate(50);
    garage[1].accelerate(120);
    garage[2].accelerate(90);
    garage[3].accelerate(200); // ограничится maxSpeed

    // Торможение некоторых машин
    garage[1].brake(40);
    garage[3].brake(70);

    cout << "Состояние транспорта:\n\n";

    // Цикл перебора всех объектов вектора
    for (Vehicle& v : garage) {
        v.getStatus(); // вывод состояния текущего объекта
    }

    return 0;
}

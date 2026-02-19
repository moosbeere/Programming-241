
#include <iostream>
#include <string>
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

    // Ускорение (не выше maxSpeed)
    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    // Торможение (не ниже 0)
    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    // Вывод информации
    void getStatus() {
        cout << "Марка: " << brand << endl;
        cout << "Макс скорость: " << maxSpeed << endl;
        cout << "Текущая скорость: " << currentSpeed << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // русский язык в консоли

    Vehicle car("Toyota", 180); // создаём объект

    car.getStatus();
    cout << "------\n";

    car.accelerate(70); // разгон
    car.getStatus();

    cout << "------\n";

    car.brake(50); // торможение
    car.getStatus();

    return 0;
}
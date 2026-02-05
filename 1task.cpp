#include <iostream>
#include <string>
#include <locale>  
#include <clocale> 

using namespace std;

class Vehicle {
private:
    // создаем поля класса
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    // конструктор для инициализации марки и максимальной скорости
    Vehicle(string brand, int maxSpeed) {
        this->brand = brand;
        this->maxSpeed = maxSpeed;
        this->currentSpeed = 0; // текущая скорость по умолчанию 0
    }

    // метод для увеличения текущей скорости
    void accelerate(int increment) {
        if (increment > 0) {
            currentSpeed += increment;
            // проверяем, чтобы скорость не превысила максимальную
            if (currentSpeed > maxSpeed) {
                currentSpeed = maxSpeed;
            }
            cout << brand << ": Скорость увеличена на " << increment << " км/ч. Текущая скорость: " << currentSpeed << " км/ч" << endl;
        }
    }

    // метод для уменьшения текущей скорости
    void brake(int decrement) {
        if (decrement > 0) {
            currentSpeed -= decrement;
            // проверяем, чтобы скорость не стала отрицательной
            if (currentSpeed < 0) {
                currentSpeed = 0;
            }
            cout << brand << ": Скорость уменьшена на " << decrement << " км/ч. Текущая скорость: " << currentSpeed << " км/ч" << endl;
        }
    }

    // метод для вывода информации о транспортном средстве
    void getStatus() {
        cout << "=== Статус транспортного средства ===" << endl;
        cout << "Марка: " << brand << endl;
        cout << "Максимальная скорость: " << maxSpeed << " км/ч" << endl;
        cout << "Текущая скорость: " << currentSpeed << " км/ч" << endl;
        cout << "====================================" << endl;
    }

    // геттеры
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

int main() {
   
    setlocale(LC_ALL, "RUSSIAN");

    // создаем транспортное средство
    Vehicle car("Toyota", 180);

    // выводим начальный статус
    car.getStatus();

    // увеличиваем скорость
    car.accelerate(50);
    car.accelerate(100);
    car.accelerate(50); 

    // выводим статус после ускорения
    car.getStatus();

    // уменьшаем скорость
    car.brake(70);
    car.brake(100); 

 
    car.getStatus();
 
    return 0;
}
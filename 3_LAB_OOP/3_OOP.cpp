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
    virtual void getStatus() {
        cout << "=== Статус транспортного средства ===" << endl;
        cout << "Марка: " << brand << endl;
        cout << "Максимальная скорость: " << maxSpeed << " км/ч" << endl;
        cout << "Текущая скорость: " << currentSpeed << " км/ч" << endl;
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

class FreightVehicle : public Vehicle {
private:
        int cargoCapacity;
public:
    FreightVehicle(string brand, int maxSpeed, int cargoCapacity) : Vehicle(brand, maxSpeed) {

        this->cargoCapacity = cargoCapacity;

    }


    void getStatus() override { 
        Vehicle::getStatus(); 
        cout << "Грузоподъемность: " << cargoCapacity << " кг" << endl; 
        cout << "====================================" << endl;
    }
    

    
};



int main() {



    setlocale(LC_ALL, "RUSSIAN");



    FreightVehicle truck("Mercedes", 120, 5000);
    truck.accelerate(50);
    truck.getStatus();
    

    return 0;

}
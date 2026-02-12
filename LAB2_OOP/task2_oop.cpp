#include <iostream>
#include <string>
#include <locale>  
#include <clocale> 
#include <vector> 



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

           // cout << brand << ": Скорость увеличена на " << increment << " км/ч. Текущая скорость: " << currentSpeed << " км/ч" << endl;

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

           // cout << brand << ": Скорость уменьшена на " << decrement << " км/ч. Текущая скорость: " << currentSpeed << " км/ч" << endl;

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
    

    // Создаем массивв обьектов класса
    Vehicle vehiclesArray[] = {
        Vehicle("Toyota Camry", 220),
        Vehicle("Harley-Davidson", 280),
        Vehicle("Scania R500", 140),
        Vehicle("Yamaha R6", 260),
        Vehicle("Renault Logan", 180)
    };

    vehiclesArray[0].accelerate(190);
    vehiclesArray[1].accelerate(93);
    vehiclesArray[2].accelerate(101);
    vehiclesArray[3].accelerate(230);
    vehiclesArray[4].accelerate(179);

    vehiclesArray[3].brake(80);
    vehiclesArray[5].brake(4);



   
    cout << "========== ВЫВОДИМ СТАТУС ВСЕХ ТРАНСПОРТНЫХ СРЕДСТВ ==========" << endl;
    
    for ( int i = 0; i < 5; i++) {
        
        
        
        vehiclesArray[i].getStatus();


    }

}

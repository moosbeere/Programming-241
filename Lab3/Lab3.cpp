#include <iostream>
#include "Vehicle.h"
#include "FreightVehicle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Тестирование родительского класса Vehicle" << endl;
    Vehicle car("Toyota", 200);
    car.accelerate(150);
    car.getStatus();

    cout << "\nТестирование дочернего класса FreightVehicle" << endl;

    // Создаем грузовой автомобиль
    FreightVehicle truck("Камаз", 120, 15.5);

    // Используем методы родительского класса
    truck.accelerate(80);
    truck.brake(20);

    // Вызываем переопределенный метод
    truck.getStatus();

    cout << "\nЕще один грузовик" << endl;
    FreightVehicle scania("Scania", 140, 20.0);
    scania.accelerate(100);
    scania.getStatus();

    return 0;
}
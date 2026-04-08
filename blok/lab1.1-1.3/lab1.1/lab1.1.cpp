#include <iostream>
#include "Vehicle.h"
#include <vector>
#include <windows.h>
#include "FreightVehicle.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");


    /*Vehicle m("Мерседес", 80);
    m.getStatus();
    m.accelerate(80);
    m.accelerate(1);
    m.getStatus();
    m.brake(80);
    m.brake(1);
    m.getStatus();*/


    /*vector<Vehicle> list;
    for (int i = 0; i < 3; i++) {
        string name;
        int maxSpeed;
        cout << "Введите название марки автомобиля" << endl;
        cin >> name;
        cout << "Введите максимальную возможную скорость автомобиля" << endl;
        cin >> maxSpeed;
        list.push_back(Vehicle(name, maxSpeed));
    }

    string status = "н";
    while (status == "н") {
        int n;
        float a;
        float b;
        cout << "Введите номер автомобиля" << endl;
        cin >> n;
        cout << "Введите увеличение скорости для этого автомобиля" << endl;
        cin >> a;
        cout << "Введите уменьшение скорости для этого автомобиля" << endl;
        cin >> b;
        list[n - 1].accelerate(a);
        list[n - 1].brake(b);
        cout << "Хотите завершить програму? д/н" << endl;
        cin >> status;
    }

    for (Vehicle i : list) {
        i.getStatus();
    }*/

    FreightVehicle b("Большая", 60, 3);
    b.accelerate(30);
    b.brake(20);
    b.getStatus();
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include <windows.h>
#include <clocale>

#include "Car.h"
#include "Truck.h"
#include "AssignedRoute.h"
#include "Warehouse.h"

using namespace std;

// ======================================================
// Главная функция
// ======================================================

int main() {

    // ==================================================
    // Русский язык
    // ==================================================

    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ==================================================
    // Маршрут
    // ==================================================

    Route route1("Рига",
        "Юрмала",
        25);

    // ==================================================
    // unique_ptr
    // ==================================================

    unique_ptr<Vehicle> truck =
        make_unique<Truck>(
            "Volvo Truck",
            120
        );

    // Передача владения
    AssignedRoute assigned1(
        route1,
        move(truck)
    );

    cout << "===== Маршрут ====="
        << endl;

    assigned1.printInfo();

    cout << endl;

    // ==================================================
    // Статический метод
    // ==================================================

    DispatchCenter::report();

    cout << endl;

    // ==================================================
    // Warehouse<int>
    // ==================================================

    Warehouse<int> numbers;

    numbers.addItem(101);
    numbers.addItem(202);

    cout << "===== Номера ====="
        << endl;

    cout << numbers.getItem(0)
        << endl;

    cout << "Всего: "
        << numbers.getTotalItems()
        << endl;

    cout << endl;

    // ==================================================
    // Warehouse<string>
    // ==================================================

    Warehouse<string> cargos;

    cargos.addItem("Телевизоры");
    cargos.addItem("Ноутбуки");

    cout << "===== Грузы ====="
        << endl;

    cout << cargos.getItem(0)
        << endl;

    cout << "Всего: "
        << cargos.getTotalItems()
        << endl;

    cout << endl;

    // ==================================================
    // Сортировка
    // ==================================================

    Car car1("BMW", 240);

    Car car2("Audi", 220);

    Truck truck1("MAN", 140);

    vector<Vehicle*> vehicles;

    vehicles.push_back(&car1);
    vehicles.push_back(&car2);
    vehicles.push_back(&truck1);

    // sort
    sort(vehicles.begin(),
        vehicles.end(),

        [](Vehicle* a,
            Vehicle* b) {

                return *a < *b;
        });

    cout << "===== Сортировка ====="
        << endl;

    for (Vehicle* v : vehicles) {

        v->printInfo();
    }

    return 0;
}
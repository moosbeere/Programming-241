#include <iostream>
#include <memory>  // для unique_ptr и make_unique
using namespace std;

#include "Route.h"
#include "Unit.h"

int main() {
    setlocale(LC_ALL, "RU");

    // Создаем маршруты
    Route route1;
    route1.startPoint = "Душанбе";
    route1.endPoint = "Москва";
    route1.length = 2500;

    Route route2;
    route2.startPoint = "Москва";
    route2.endPoint = "Питер";
    route2.length = 700;

    cout << "=== ДЕМОНСТРАЦИЯ unique_ptr ===\n" << endl;

    // 1. СОЗДАНИЕ с передачей владения
    {
        cout << "Пример 1: Создание с Car" << endl;

        // Создаем unique_ptr на Car
        unique_ptr<TransportUnit> carPtr = make_unique<Car>("A123BC");

        // Передаем владение в AssignedRoute
        AssignedRoute assigned1(move(carPtr), &route1);

        // carPtr теперь пустой! Владеет assigned1
        assigned1.PrintInfo();

        // Здесь assigned1 удалится, и транспорт удалится автоматически
    }

    cout << "\n------------------------\n" << endl;

    // 2. СОЗДАНИЕ СРАЗУ В КОНСТРУКТОРЕ
    {
        cout << "Пример 2: Создание с Truck сразу в конструкторе" << endl;

        // Создаем unique_ptr прямо в конструкторе
        AssignedRoute assigned2(make_unique<Truck>("B456CD"), &route2);
        assigned2.PrintInfo();
    }

    cout << "\n------------------------\n" << endl;

    // 3. НЕСКОЛЬКО МАРШРУТОВ
    {
        cout << "Пример 3: Несколько маршрутов" << endl;

        // Создаем несколько назначенных маршрутов
        AssignedRoute trip1(make_unique<Car>("C789EF"), &route1);
        AssignedRoute trip2(make_unique<Truck>("D012GH"), &route2);
        AssignedRoute trip3(make_unique<Car>("E345IJ"), &route1);

        trip1.PrintInfo();
        trip2.PrintInfo();
        trip3.PrintInfo();

        // Считаем общую стоимость
        double total = trip1.calculateTotalCost() +
            trip2.calculateTotalCost() +
            trip3.calculateTotalCost();

        cout << "\nОБЩАЯ СТОИМОСТЬ ВСЕХ ПОЕЗДОК: " << total << " у.е." << endl;
    }

    cout << "\n=== КОНЕЦ ПРОГРАММЫ ===" << endl;
    cout << "Весь транспорт автоматически удален!" << endl;

    return 0;
}
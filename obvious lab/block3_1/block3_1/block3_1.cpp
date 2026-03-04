#include <iostream>
#include <vector>
#include "TransportUnit.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<TransportUnit*> garage;

    cout << "СОЗДАНИЕ ТРАНСПОРТА" << endl;

    garage.push_back(new Car("123qwer"));
    garage.push_back(new Car("0987po"));
    garage.push_back(new Truck(20.5, "lkjhg78"));
    garage.push_back(new Truck(8.0, "123fvdv"));

    cout << "ИНФОРМАЦИЯ О ТРАНСПОРТЕ" << endl;

    for (size_t i = 0; i < garage.size(); i++) {
        cout << i + 1 << ". " << garage[i]->getType() << endl;
        cout << "   Плата за 100км: "
            << garage[i]->calculateToll(100) << " у.е." << endl;
        cout << "   Номер: " << garage[i]->getLicensePlate() << endl;
    }

    TransportUnit::report();

    for (auto v : garage) {
        delete v;
    }

    TransportUnit::report();

    return 0;
}
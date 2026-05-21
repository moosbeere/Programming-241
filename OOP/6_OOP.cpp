#include <iostream>
#include <string>

using namespace std;

// Диспетчерский центр
class DispatchCenter {
public:
    static int totalVehiclesDispatched;

    static void report() {
        cout << "Общее кол-во транспорта: "
             << totalVehiclesDispatched << endl;
    }
};

// Инициализация статического поля
int DispatchCenter::totalVehiclesDispatched = 0;

// Базовый класс транспорта
class Vehicle {
protected:
    string name;

public:
    Vehicle(string n) : name(n) {
        // Регистрация транспорта
        DispatchCenter::totalVehiclesDispatched++;
    }

    void printInfo() const {
        cout << "Транспорт: " << name << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string n) : Vehicle(n) {}
};

int main() {
    setlocale(LC_ALL, "RU");
    Car car1("BMW");
    car1.printInfo();
    DispatchCenter::report();

    Car car2("Merc");
    car2.printInfo();
    DispatchCenter::report();
    return 0;
}
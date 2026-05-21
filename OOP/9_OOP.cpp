#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Vehicle {
private:
    string name;
    int maxSpeed;

public:
    Vehicle(string n, int speed) : name(n), maxSpeed(speed) {}

    // Перегрузка оператора <
    bool operator<(const Vehicle& other) const {
        return maxSpeed < other.maxSpeed;
    }

    void printInfo() const {
        cout << name << " Максимальная скорость: " << maxSpeed << " км/ч" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    vector<Vehicle> vehicles = {
        Vehicle("Truck", 90),
        Vehicle("Car", 180),
        Vehicle("Bus", 120),
        Vehicle("Motorcycle", 220)
    };

    // Сортировка по maxSpeed
    sort(vehicles.begin(), vehicles.end());

    cout << "Транспорт после сортировки:" << endl;

    for (const Vehicle& v : vehicles) {
        v.printInfo();
    }

    return 0;
}
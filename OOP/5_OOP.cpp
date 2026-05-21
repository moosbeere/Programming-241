#include <iostream>
#include <string>

using namespace std;

// Абстрактный базовый класс
class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0;
};

// Легковушка
class Car : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.1;
    }
};

// Грузовик
class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.3 + 5.0;
    }
};

// маршрут
class Route {
private:
    string startPoint;
    string endPoint;
    double length;

public:
    Route(string start, string end, double len) : startPoint(start), endPoint(end), length(len) {}

    double getLength() const {
        return length;
    }

    void printInfo() const {
        cout << "Маршрут из " << startPoint << " в " << endPoint << endl;
        cout << "Длина: " << length << " км" << endl;
    }
};

// назначенный маршрут
class AssignedRoute {
private:
    Route route;
    TransportUnit* transport;

public:
    AssignedRoute(const Route& r, TransportUnit* t) : route(r), transport(t) {}

    double calculateTotalCost() const {
        return transport->calculateToll(route.getLength());
    }

    void printDetails() const {
        route.printInfo();

        cout << "Стоимость проезда: "
             << calculateTotalCost()
             << " у.е." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Car car;
    Truck truck;

    Route route1("А", "Б", 180);
    Route route2("Б", "В", 350);

    AssignedRoute trip1(route1, &car);
    AssignedRoute trip2(route2, &truck);

    cout << "Поездка 1:" << endl;
    trip1.printDetails();

    cout << endl;

    cout << "Поездка 2:" << endl;
    trip2.printDetails();

    return 0;
}
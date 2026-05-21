#include <iostream>
#include <string>
#include <memory>

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

    // unique_ptr владеет объектом транспорта
    unique_ptr<TransportUnit> transport;

public:
    AssignedRoute(const Route& r, unique_ptr<TransportUnit> t) : route(r), transport(move(t)) {}

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
    Route route1("A", "B", 700);

    // Передача объекта Truck во владение
    AssignedRoute trip(route1, make_unique<Truck>()
    );

    trip.printDetails();

    return 0;
}
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0;
    virtual ~TransportUnit() = default;
}; 

class Car : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.1;
    }
};

class Truck : public TransportUnit {
public:
    double calculateToll(double distance) const override {
        return distance * 0.3 + 5.0;
    }
};

class Route {
private:
    string startPoint;
    string endPoint;
    double length;

public:
    Route(string start, string end, double len): startPoint(start), endPoint(end), length(len) {
    }

    double getLength() const {
        return length;
    }

    void printInfo() const {
        cout << "Маршрут: " << startPoint << " - " << endPoint << " (" << length << " км)" << endl;
    }
};

class AssignedRoute {
private:
    Route route;
    unique_ptr<TransportUnit> transport;

public:
    AssignedRoute(Route r, unique_ptr<TransportUnit> t): route(r), transport(move(t)) {}

    double calculateTotalCost() const {
        return transport->calculateToll(route.getLength());
    }

    void printFinal() const {
        route.printInfo();
        cout << "Стоимость проезда: " << calculateTotalCost() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Route route1("Москва", "Тула", 180);
    Route route2("Казань", "Самара", 350);

    AssignedRoute assigned1(route1, make_unique<Car>());
    AssignedRoute assigned2(route2, make_unique<Truck>());

    assigned1.printFinal();
    cout << endl;
    assigned2.printFinal();

    return 0;
}
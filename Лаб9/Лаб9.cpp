#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Vehicle {
private:
    string name;
    int maxSpeed;

public:
    Vehicle(string n, int s) {
        name = n;
        maxSpeed = s;
    }

    string getName() const {
        return name;
    }

    int getMaxSpeed() const {
        return maxSpeed;
    }

    bool operator<(Vehicle& second) {
        return maxSpeed < second.maxSpeed;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Vehicle vehicles[4] = {
        Vehicle("Автомобиль",180),
        Vehicle("Мотоцикл",170),
        Vehicle("Тягач",85),
        Vehicle("Автобус",80)
    };

    sort(vehicles, vehicles + 3);

    for (int i = 0; i < 4; i++) {
        cout << vehicles[i].getName() << " - " << vehicles[i].getMaxSpeed() << endl;
    }

}
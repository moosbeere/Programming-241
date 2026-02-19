#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(string b, int mS) {
        brand = b;
        maxSpeed = mS;
        currentSpeed = 0;
    }

    void accelerate(int increment) {
        if (increment <= maxSpeed) {
            currentSpeed += increment;
            if (increment > maxSpeed) currentSpeed = maxSpeed;
        }
    }

    void brake(int decrement) {
        if (decrement > 0) {
            currentSpeed -= decrement;
            if (currentSpeed < 0) currentSpeed = 0;
        }
    }

    void getStatus() {
        cout << "Марка: " << brand << endl;
        cout << "Максимальная скорость: " << maxSpeed << endl;
        cout << "Текущая скорость: " << currentSpeed << endl;
    }
};

class FreightVehicle : public Vehicle {
private:
    float cargoCapacity;

public:
    FreightVehicle(string b, int mS, float capacity): Vehicle(b, mS)
    {
        cargoCapacity = capacity;
    }

    void getStatus() {
        Vehicle::getStatus();
        cout << "Грузоподъемность: " << cargoCapacity << " т" << endl;
    }
};


int main() {
    setlocale(LC_ALL, "RU");

    FreightVehicle truck("Volvo", 140, 20.5f);

    truck.accelerate(100);
    truck.getStatus();

    return 0;
}

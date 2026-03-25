#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(string vehicle_brand, int vehicle_maxSpeed) {
        brand = vehicle_brand;
        maxSpeed = vehicle_maxSpeed;
        currentSpeed = 0;
    }

    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    void getStatus() {
        cout << "марка: " << brand << endl;
        cout << "текущая скорость: " << currentSpeed << endl;
    }
};

int main() {
    Vehicle car1("nissan", 220);
    car1.accelerate(2);
    car1.brake(15);
    car1.getStatus();

    return 0;
}
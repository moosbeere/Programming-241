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
        if (increment <= maxSpeed and increment > currentSpeed) currentSpeed += increment;
        if (increment < currentSpeed) currentSpeed = maxSpeed;
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

int main() {
    setlocale(LC_ALL, "RU");
    Vehicle car("BMW", 180);

    car.getStatus();
    cout << endl;

    car.accelerate(-50);
    car.getStatus();
    cout << endl;

    car.accelerate(200);
    car.getStatus();
    cout << endl;

    car.brake(70);
    car.getStatus();
    cout << endl;

    car.brake(200);
    car.getStatus();

    return 0;
}

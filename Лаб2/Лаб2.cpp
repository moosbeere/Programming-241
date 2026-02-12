#include <iostream>
#include <vector>
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
        if (increment < currentSpeed or increment > maxSpeed) currentSpeed = maxSpeed;
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

    Vehicle park[3] = {
        Vehicle("BMW", 180),
        Vehicle("Ford", 185),
        Vehicle("Honda", 190)
    };

    cout << "Разгон: \n" << endl;

    park[0].accelerate(100);
    park[1].accelerate(250);
    park[2].accelerate(150);

    for (int i = 0; i < 3; i++) {
        park[i].getStatus();
    }

    cout << "\nТорможение: \n\n";

    park[1].brake(50);
    park[2].brake(200);

    for (int i = 0; i < 3; i++) {
        park[i].getStatus();
    }

    return 0;
}

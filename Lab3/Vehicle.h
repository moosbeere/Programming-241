#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int maxSpeed;
    int currentSpeed;
public:
    Vehicle(string str, int mS);
    void accelerate(int num);
    void brake(int num);
    virtual void getStatus();  // Виртуальный метод для возможности переопределения
};
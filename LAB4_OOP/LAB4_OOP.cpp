#include <iostream>
#include <vector>
using namespace std;

class TransportUnit {
public:
    virtual double calculateToll(double distance) const = 0; 
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

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    
    Car myCar;
    Truck myTruck;

   
    vector<TransportUnit*> vehicles;
    vehicles.push_back(&myCar);
    vehicles.push_back(&myTruck);

    double distance = 100.0; 
    for (TransportUnit* vehicle : vehicles) {
        cout << "Плата за " << distance << " км: " << vehicle->calculateToll(distance) << " у.е." << endl;
    }
    return 0;
}




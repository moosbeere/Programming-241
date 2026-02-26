#include <string>

class Vehicle {
private:
    std::string brand;
    int maxSpeed;
    int currentSpeed;
public:
    Vehicle(std::string str, int mS);
    void accelerate(int num);
    void brake(int num);
    void getStatus();
    bool operator<(const Vehicle& other) const;
};

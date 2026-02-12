#include "Vehicle.h"

class FreightVehicle : public Vehicle {
private:
    double cargoCapacity;
public:
    // Конструктор с вызовом родительского конструктора
    FreightVehicle(string brand, int maxSpeed, double cargoCap);

    // Переопределенный метод getStatus()
    void getStatus() override;
};
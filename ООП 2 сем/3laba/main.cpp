#include "FreightVehicle.h"

int main() {
    // Создаём объект грузового транспорта
    FreightVehicle truck("КамАЗ", 12.5);

    // Прямой вызов метода через объект
    std::cout << "Информация о грузовике:\n";
    truck.getStatus();

    // Создаём указатель на базовый класс, который указывает на тот же объект
    Vehicle* ptr = &truck;

    std::cout << "\nЧерез указатель на Vehicle:\n";
    (*ptr).getStatus();  

    return 0;
}

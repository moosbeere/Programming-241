#include <iostream>
#include "FreightVehicle.h"

int main() {
    // Создаём объект грузового транспорта
    FreightVehicle truck("КамАЗ", 12.5);

    // Вызываем переопределённый метод getStatus()
    std::cout << "Информация о грузовике:\n";
    truck.getStatus();

    // Демонстрация полиморфизма: указатель на базовый класс, объект производного
    Vehicle* ptr = &truck;
    std::cout << "\nЧерез указатель на Vehicle:\n";
    ptr->getStatus();  // вызовется версия FreightVehicle (благодаря virtual)

    return 0;
}
#pragma once
#include <iostream>

class DispatchCenter {
private:
    // Статическое поле: одно на все объекты класса
    static int totalVehiclesDispatched;
public:
    // Метод для регистрации транспорта
    static void registerVehicle() 
    {
        totalVehiclesDispatched++;
    }
    // Статический метод для отчета
    static void report() {
        std::cout << "Всего машин обслужено: " << totalVehiclesDispatched << std::endl;
    }
};


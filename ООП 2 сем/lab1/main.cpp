#include "Vehicle.h"
#include <iostream>
#include <windows.h> 

using namespace std;

int main() {
  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Создаём объект (экземпляр класса Vehicle)
    Vehicle myCar("Toyota", 180);
    
    // Выводим начальное состояние
    cout << "--- Начальное состояние ---" << endl;
    myCar.getStatus();
    
    // Разгоняемся
    cout << "\n--- Разгон на 50 км/ч ---" << endl;
    myCar.accelerate(50);
    myCar.getStatus();
    
    // Пытаемся разогнаться сильно (должен сработать ограничитель)
    cout << "\n--- Разгон на 150 км/ч ---" << endl;
    myCar.accelerate(150);
    myCar.getStatus();
    
    // Тормозим
    cout << "\n--- Торможение на 30 км/ч ---" << endl;
    myCar.brake(30);
    myCar.getStatus();
    
    // Тормозим в пол (должен сработать ограничитель)
    cout << "\n--- Торможение на 200 км/ч ---" << endl;
    myCar.brake(200);
    myCar.getStatus();
    
    return 0;
}

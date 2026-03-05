/*Задание 1: "Транспортное средство" (Базовый класс)

Создайте класс Vehicle (Транспортное средство).

• Поля (private): brand (марка, строка), maxSpeed (максимальная скорость, число), currentSpeed (текущая скорость, число).

• Методы (public):

    – Конструктор для инициализации марки и максимальной скорости (текущая скорость = 0).

    – accelerate(int increment) - увеличивает текущую скорость, но не более maxSpeed.

    – brake(int decrement) - уменьшает текущую скорость, но не ниже 0.

    – getStatus() - выводит в консоль информацию о транспортном средстве (все поля).

• Цель: Освоить создание класса, инкапсуляцию данных, работу с конструктором и простыми методами.*/

/*Задание 2: "Парк транспортных средств" (Работа с массивами объектов)

На основе класса Vehicle из задания 1 создайте в функции main() массив (или std::vector) из 3-5 различных транспортных средств. Смоделируйте их движение: для каждого вызовите accelerate() с разными значениями, затем для некоторых - brake(). В конце выведите статус всех транспортных средств.

• Цель: Научиться создавать и управлять множеством объектов.*/

#include <iostream>
#include "Vehicle.h"
#include <string>
#include <vector>
#include "FreightVehicle.h"
int main()
{
    setlocale(LC_ALL, "RU");
    Vehicle Lada("Lada", 180, 60);

    cout << "--------------------------------------------\nЗадание 1\n--------------------------------------------\n";

    Lada.getStatus();
    cout << endl;
    Lada.accelerate(30);
    Lada.getStatus();
    cout << endl;
    Lada.accelerate(170);
    Lada.getStatus();
    cout << endl;
    Lada.brake(30);
    Lada.getStatus();
    cout << endl;
    Lada.brake(160);
    Lada.getStatus();
    cout << endl;

    cout << "--------------------------------------------\nЗадание 2\n--------------------------------------------\n";
    

    /*Задание 2: "Парк транспортных средств" (Работа с массивами объектов)

На основе класса Vehicle из задания 1 создайте в функции main() массив (или std::vector) из 3-5 различных транспортных средств. Смоделируйте их движение: для 
каждого вызовите accelerate() с разными значениями, затем для некоторых - brake(). В конце выведите статус всех транспортных средств.

• Цель: Научиться создавать и управлять множеством объектов.*/
    


    vector<Vehicle> vehicles;

    vehicles.push_back(Vehicle("BMW", 250, 0));
    vehicles.push_back(Vehicle("Mercedes", 240, 0));
    vehicles.push_back(Vehicle("Audi", 230, 0));
    vehicles.push_back(Vehicle("Toyota", 200, 0));
    vehicles.push_back(Vehicle("Ford", 180, 0));


    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i].accelerate(50 + i * 10);
    }

    vehicles[1].brake(30);  // Мерседес
    vehicles[3].brake(40);  // Тойота

    vehicles[0].accelerate(30);  // БМВ
    vehicles[2].accelerate(20);  // АУДИ

    for (int i = 0; i < vehicles.size(); i++) {
        cout << i + 1 << ". ";
        vehicles[i].getStatus();
        cout << endl;
    }
    
    cout << "--------------------------------------------\nЗадание 3\n--------------------------------------------\n";

    /*Задание 3: "Грузовой транспорт" (Наследование)

Создайте класс FreightVehicle, который наследуется от Vehicle.

• Добавьте новое поле (private): cargoCapacity (грузоподъемность в тоннах, число).

• Переопределите метод getStatus(), чтобы он выводил также информацию о грузоподъемности.

• Создайте конструктор для FreightVehicle, который инициализирует поля родителя и новое поле.

• Цель: Понять принцип наследования, расширения функциональности базового класса.*/
    
    FreightVehicle kamaz("Kamaz", 120, 0, 15.5);
    FreightVehicle man("MAN", 130, 0, 12.0);
    FreightVehicle volvo("Volvo", 140, 0, 18.0);

    cout << "\nНачальное состояние грузовиков:\n";
    kamaz.getStatus();
    man.getStatus();
    volvo.getStatus();

    kamaz.accelerate(40);
    man.accelerate(50);
    volvo.accelerate(45);

    kamaz.brake(20);
    man.brake(30);

    cout << "\nФинальное состояние грузовиков:\n";
    kamaz.getStatus();
    man.getStatus();
    volvo.getStatus();

    cout << "Грузоподъемность Kamaz: " << kamaz.getCargoCapacity() << " тонн" << endl;
    cout << "Грузоподъемность MAN: " << man.getCargoCapacity() << " тонн" << endl;
    cout << "Грузоподъемность Volvo: " << volvo.getCargoCapacity() << " тонн" << endl;
    return 0;


}
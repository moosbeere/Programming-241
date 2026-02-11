//Задание 2: "Парк транспортных средств" (Работа с массивами объектов)
//
//На основе класса Vehicle из задания 1 создайте в функции main() массив(или std::vector) из 3 - 5 различных транспортных средств.Смоделируйте их движение : для каждого вызовите accelerate() с разными значениями, затем для некоторых - brake().В конце выведите статус всех транспортных средств.
//
//• Цель : Научиться создавать и управлять множеством объектов.
#include <iostream>
#include <string>
#include <vector>
#include <clocale>

class Vehicle {
private:
    std::string brand;
    int maxSpeed;
    int currentSpeed;

public:
    Vehicle(const std::string& b, int ms) : brand(b), maxSpeed(ms), currentSpeed(0) {}

    void accelerate(int increment) {
        currentSpeed += increment;
        if (currentSpeed > maxSpeed)
            currentSpeed = maxSpeed;
    }

    void brake(int decrement) {
        currentSpeed -= decrement;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    void getStatus() const {
        std::cout << "Марка: " << brand
            << ", Макс. скорость: " << maxSpeed
            << ", Текущая скорость: " << currentSpeed
            << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");  
   

    // Создаём вектор с несколькими транспортными средствами
    std::vector<Vehicle> park;

    // Добавляем 5 различных объектов
    park.push_back(Vehicle("Toyota", 180));
    park.push_back(Vehicle("BMW", 220));
    park.push_back(Vehicle("Lada", 150));
    park.push_back(Vehicle("Volvo", 200));
    park.push_back(Vehicle("Tesla", 250));

    // Выводим начальное состояние
    std::cout << "--- Начальное состояние ---\n";
    for (const auto& v : park) {
        v.getStatus();
    }

    // Моделируем движение: каждый разгоняем с разными значениями
    std::cout << "\n--- Разгон ---\n";
    park[0].accelerate(50);   // Toyota +50
    park[1].accelerate(100);  // BMW +100
    park[2].accelerate(30);   // Lada +30
    park[3].accelerate(80);   // Volvo +80
    park[4].accelerate(200);  // Tesla +200 (достигнет максимума 250)

    // Вывод после разгона
    for (const auto& v : park) {
        v.getStatus();
    }

    // Некоторые транспортные средства тормозят
    std::cout << "\n--- Торможение ---\n";
    park[0].brake(20);   // Toyota -20
    park[2].brake(40);   // Lada -40
    park[4].brake(100);  // Tesla -100

    // Итоговое состояние
    std::cout << "\n--- Итоговое состояние ---\n";
    for (const auto& v : park) {
        v.getStatus();
    }

    return 0;
}
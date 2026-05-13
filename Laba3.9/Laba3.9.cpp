/*Задание 9: "Оператор сравнения транспортных средств" (Перегрузка операторов)
В классе Vehicle перегрузите оператор < (меньше) для сравнения двух транспортных средств по их максимальной скорости (maxSpeed). 
Создайте массив Vehicle, отсортируйте его с помощью std::sort и выведите результат. std::sort будет использовать ваш перегруженный оператор.
• Цель: Научиться перегружать операторы для работы с пользовательскими типами*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Vehicle {
private:
    string name;
    int maxSpeed;

public:
    Vehicle(string n, int s) : name(n), maxSpeed(s) {}

    // Перегружаем оператор <
    // Он должен возвращать true, если скорость текущего объекта меньше другого
    bool operator<(const Vehicle& other) const {
        return maxSpeed < other.maxSpeed;
    }

    void print() const {
        cout << name << " (скорость: " << maxSpeed << " км/ч)" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    vector<Vehicle> fleet;
    fleet.push_back(Vehicle("Велосипед", 25));
    fleet.push_back(Vehicle("Гоночный болид", 350));
    fleet.push_back(Vehicle("Грузовик", 90));
    fleet.push_back(Vehicle("Легковушка", 180));

    cout << "До сортировки:" << endl;
    for (const auto& v : fleet) v.print();

    // Сортировка! Она сама вызовет наш оператор < внутри себя
    sort(fleet.begin(), fleet.end());

    cout << "\nПосле сортировки (по возрастанию скорости):" << endl;
    for (const auto& v : fleet) v.print();

    return 0;
}

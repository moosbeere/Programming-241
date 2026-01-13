#include "Header.h"
#include <iostream>

// Конструктор с параметрами
Weapon::Weapon(const std::string& n, int d, double w)
    : name(n), damage(d), weight(w) {
}

// Конструктор без параметров
Weapon::Weapon() : Weapon("Default Sword", 10, 5.0) {}

// Деструктор
Weapon::~Weapon() {
    std::cout << "Удаляется оружие: "
        << name << ", урон: " << damage
        << ", вес: " << weight << std::endl;
}

// Метод вывода данных
void Weapon::print() const {
    std::cout << "Название: " << name
        << ", Урон: " << damage
        << ", Вес: " << weight << std::endl;
}

// Проверка веса
bool Weapon::isTooHeavy(double maxWeight) const {
    return weight > maxWeight;
}

// Суммарный вес с другим оружием
double Weapon::totalWeight(const Weapon& other) const {
    return totalWeight(other.weight); // используем перегрузку
}

// Суммарный вес с весом
double Weapon::totalWeight(double w) const {
    return weight + w;
}

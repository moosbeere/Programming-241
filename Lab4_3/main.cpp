#include "Header.h"
#include <iostream>

using namespace std;

// Конструктор с параметрами
Header::Header(string n, int d, float w) {
    name = n;
    damage = d;
    weight = w;
}

// Конструктор без параметров
Header::Header() : Header("Меч", 10, 3.0f) {}

// Деструктор
Header::~Header() {
    cout << "Удаляется оружие: " << name
        << ", урон: " << damage
        << ", вес: " << weight << endl;
}

// Вывод информации
void Header::print() {
    cout << "Оружие: " << name
        << ", урон: " << damage
        << ", вес: " << weight << endl;
}

// Проверка веса
bool Header::isTooHeavy(float maxWeight) {
    return maxWeight < weight;
}

// Перегрузки totalWeight
float Header::totalWeight(float w) {
    return weight + w;
}

float Header::totalWeight(Header other) {
    return totalWeight(other.weight);
}

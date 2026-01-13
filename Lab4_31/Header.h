#ifndef HEADER_H
#define HEADER_H

#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    double weight;

public:
    // Конструктор с параметрами
    Weapon(const std::string& n, int d, double w);

    // Конструктор без параметров
    Weapon();

    // Деструктор
    ~Weapon();

    // Метод вывода данных
    void print() const;

    // Проверка, слишком ли тяжелое оружие
    bool isTooHeavy(double maxWeight) const;

    // Метод для суммарного веса с другим оружием
    double totalWeight(const Weapon& other) const;

    // Перегруженный метод для суммарного веса с весом
    double totalWeight(double w) const;
};

#endif // HEADER_H

#include <iostream>
#include <vector>

// Абстрактный базовый класс "Транспортная единица"
class TransportUnit
{
public:
    // Чисто виртуальная функция расчёта платы за проезд
    virtual double calculateToll(double distance) const = 0;

    // Виртуальный деструктор для корректного удаления через указатель базового класса
    virtual ~TransportUnit() = default;
};

// Легковой автомобиль
class Car : public TransportUnit
{
public:
    // Плата = distance * 0.1
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.1;
    }
};

// Грузовик
class Truck : public TransportUnit
{
public:
    // Плата = distance * 0.3 + 5.0
    double calculateToll(double distance) const override
    {
        if (distance < 0)
            distance = 0;
        return distance * 0.3 + 5.0;
    }
};

int main()
{
    const double distance = 100.0; // расстояние в км

    // Можем хранить разные типы транспорта в одном контейнере указателей на базовый класс
    std::vector<TransportUnit*> units;
    units.push_back(new Car());
    units.push_back(new Truck());
    units.push_back(new Car());
    units.push_back(new Truck());

    std::cout << "Distance: " << distance << " km\n\n";

    for (std::size_t i = 0; i < units.size(); ++i)
    {
        double toll = units[i]->calculateToll(distance);
        std::cout << "TransportUnit #" << i + 1
                  << " toll = " << toll << " units\n";
    }

    // Освобождаем память
    for (TransportUnit* u : units)
    {
        delete u;
    }

    return 0;
}

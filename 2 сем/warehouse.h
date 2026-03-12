#pragma once

#include <stdexcept>
#include <vector>

// Шаблонный класс "Склад".
// Параметр T задаёт тип груза, который будет храниться.
template <typename T>
class Warehouse
{
private:
    // Контейнер для хранения элементов (грузов).
    std::vector<T> items;

public:
    // Добавить элемент на склад.
    void addItem(const T& item)
    {
        items.push_back(item);
    }

    // Получить элемент по индексу.
    // При выходе за границы генерируется исключение std::out_of_range.
    T getItem(int index) const
    {
        if (index < 0 || index >= static_cast<int>(items.size()))
            throw std::out_of_range("Warehouse::getItem: index out of range");
        return items[static_cast<std::size_t>(index)];
    }

    // Узнать общее количество хранимых элементов.
    int getTotalItems() const
    {
        return static_cast<int>(items.size());
    }
};


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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

int main()
{
    // Пример: склад с номерами грузов (int).
    Warehouse<int> intWarehouse;
    intWarehouse.addItem(101);
    intWarehouse.addItem(202);
    intWarehouse.addItem(303);

    std::cout << "Int warehouse total: " << intWarehouse.getTotalItems() << "\n";
    std::cout << "Int warehouse item[1]: " << intWarehouse.getItem(1) << "\n\n";

    // Пример: склад с названиями грузов (std::string).
    Warehouse<std::string> stringWarehouse;
    stringWarehouse.addItem("Boxes");
    stringWarehouse.addItem("Pallets");
    stringWarehouse.addItem("Crates");

    std::cout << "String warehouse total: " << stringWarehouse.getTotalItems() << "\n";
    std::cout << "String warehouse item[2]: " << stringWarehouse.getItem(2) << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Шаблонный класс склада
template <typename T>
class Warehouse {
private:
    vector<T> items;

public:
    // Добавление элемента
    void addItem(const T& item) {
        items.push_back(item);
    }

    // Получение элемента по индексу
    T getItem(int index) const {
        return items.at(index);
    }

    // Количество элементов
    int getTotalItems() const {
        return items.size();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    // Склад с номерами грузов
    Warehouse<int> numberWarehouse;

    numberWarehouse.addItem(1);
    numberWarehouse.addItem(22);
    numberWarehouse.addItem(358);

    cout << "Склад номеров грузов:" << endl;

    for (int i = 0; i < numberWarehouse.getTotalItems(); i++) {
        cout << numberWarehouse.getItem(i) << endl;
    }

    // Склад с названиями грузов
    Warehouse<string> nameWarehouse;

    nameWarehouse.addItem("AAA");
    nameWarehouse.addItem("BBB");
    nameWarehouse.addItem("CCC");

    cout << "Склад названий грузов:" << endl;

    for (int i = 0; i < nameWarehouse.getTotalItems(); i++) {
        cout << nameWarehouse.getItem(i) << endl;
    }

    return 0;
}
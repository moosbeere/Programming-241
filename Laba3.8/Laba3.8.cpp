/*Создайте шаблонный класс Warehouse<T> (Склад).
• Поле: std::vector<T> items (контейнер для хранения "грузов" типа T).
• Методы: addItem(const T& item), T getItem(int index), int getTotalItems().
Продемонстрируйте его работу, создав:
• Warehouse<int> (склад с номерами грузов).
• Warehouse<std::string> (склад с названиями грузов)*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Warehouse {
private:
    vector<T> items; // Список наших грузов

public:
    // Добавить предмет на склад
    void addItem(const T& item) {
        items.push_back(item);
    }

    // Взять предмет по индексу
    T getItem(int index) {
        return items[index];
    }

    // Узнать общее количество
    int getTotalItems() {
        return items.size();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // 1. Склад с числами (номера грузов)
    Warehouse<int> intStock;
    intStock.addItem(101);
    intStock.addItem(102);
    intStock.addItem(105);

    cout << "Склад чисел:" << endl;
    cout << "Всего грузов: " << intStock.getTotalItems() << endl;
    cout << "Груз под индексом 1: " << intStock.getItem(1) << endl;

    cout << "----------------------" << endl;

    // 2. Склад со строками (названия грузов)
    Warehouse<string> stringStock;
    stringStock.addItem("Стиральная машина");
    stringStock.addItem("Холодильник");

    cout << "Склад названий:" << endl;
    cout << "Всего грузов: " << stringStock.getTotalItems() << endl;
    cout << "Груз под индексом 0: " << stringStock.getItem(0) << endl;

    return 0;
}

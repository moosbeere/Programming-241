#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Warehouse {
private:
    vector<T> items;

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    T getItem(int index) {
        return items.at(index);
    }

    int getTotalItems() {
        return items.size();
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Warehouse<int> number;

    number.addItem(101);
    number.addItem(202);
    number.addItem(303);

    cout << "Склад номеров грузов:" << endl;
    for (int i = 0; i < number.getTotalItems(); i++) {
        cout << number.getItem(i) << endl;
    }

    cout << endl;

    Warehouse<string> name;

    name.addItem("Телевизоры");
    name.addItem("Компьютеры");
    name.addItem("Телефоны");

    cout << "Склад названий грузов:" << endl;
    for (int i = 0; i < name.getTotalItems(); i++) {
        cout << name.getItem(i) << endl;
    }

    return 0;
}
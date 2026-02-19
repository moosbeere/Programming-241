#pragma once
#include <vector>

using namespace std;

template <typename T>
class Warehouse {
private:
    vector<T> items;

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    T getItem(int index) const {
        if (index < 0 || index >= items.size()) {
            throw out_of_range("Индекс вне диапазона");
        }
        return items[index];
    }

    int getTotalItems() {
        return items.size();
    }
};
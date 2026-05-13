#pragma once
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>

using namespace std;

// ======================================================
// Шаблонный класс Warehouse
// ======================================================

template <typename T>

class Warehouse {
private:

    vector<T> items;

public:

    // Добавление
    void addItem(const T& item) {

        items.push_back(item);
    }

    // Получение
    T getItem(int index) {

        return items[index];
    }

    // Количество
    int getTotalItems() {

        return items.size();
    }
};

#endif
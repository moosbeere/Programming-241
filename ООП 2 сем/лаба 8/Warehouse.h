#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>

template<typename T>
class Warehouse {
private:
    std::vector<T> items;
    
public:
    void addItem(const T& item) {
        items.push_back(item);
    }
    
    T getItem(int index) {
        if (index < 0 || index >= (int)items.size()) {
            throw "Нет такого груза!";
        }
        return items[index];
    }
    
    int getTotalItems() {
        return items.size();
    }
};

#endif

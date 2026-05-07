#include <iostream>
#include <string>
#include "Warehouse.h"

int main() {
    // Склад с числами
    Warehouse<int> numWarehouse;
    
    numWarehouse.addItem(10);
    numWarehouse.addItem(20);
    numWarehouse.addItem(30);
    
    std::cout << "Чисел на складе: " << numWarehouse.getTotalItems() << std::endl;
    std::cout << "Первое число: " << numWarehouse.getItem(0) << std::endl;
    std::cout << "Второе число: " << numWarehouse.getItem(1) << std::endl;
    
    // Склад со словами
    Warehouse<std::string> wordWarehouse;
    
    wordWarehouse.addItem("Стол");
    wordWarehouse.addItem("Стул");
    wordWarehouse.addItem("Шкаф");
    
    std::cout << "\nСлов на складе: " << wordWarehouse.getTotalItems() << std::endl;
    std::cout << "Первое слово: " << wordWarehouse.getItem(0) << std::endl;
    std::cout << "Второе слово: " << wordWarehouse.getItem(1) << std::endl;
    
    // Проверка ошибки
    try {
        std::cout << wordWarehouse.getItem(99);
    }
    catch (const char* msg) {
        std::cout << "\nОшибка: " << msg << std::endl;
    }
    
    return 0;
}

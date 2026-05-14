#include <iostream>
#include <string>
#include "Warehouse.h"

int main() {
    
    Warehouse<int> intWarehouse;
    
    intWarehouse.addItem(101);
    intWarehouse.addItem(202);
    intWarehouse.addItem(303);
    
    std::cout << "Склад с номерами грузов:" << std::endl;
    std::cout << "Всего грузов: " << intWarehouse.getTotalItems() << std::endl;
    std::cout << "Груз 0: " << intWarehouse.getItem(0) << std::endl;
    std::cout << "Груз 1: " << intWarehouse.getItem(1) << std::endl;
    std::cout << "Груз 2: " << intWarehouse.getItem(2) << std::endl;
    
  
    Warehouse<std::string> stringWarehouse;
    
    stringWarehouse.addItem("Книги");
    stringWarehouse.addItem("Тетради");
    stringWarehouse.addItem("Ручки");
    
    std::cout << "\nСклад с названиями грузов:" << std::endl;
    std::cout << "Всего грузов: " << stringWarehouse.getTotalItems() << std::endl;
    std::cout << "Груз 0: " << stringWarehouse.getItem(0) << std::endl;
    std::cout << "Груз 1: " << stringWarehouse.getItem(1) << std::endl;
    std::cout << "Груз 2: " << stringWarehouse.getItem(2) << std::endl;
    
    return 0;
}

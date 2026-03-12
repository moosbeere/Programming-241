#include <iostream>
#include <string>

#include "warehouse.h"

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

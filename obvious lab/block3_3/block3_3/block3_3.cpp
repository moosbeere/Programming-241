#include <iostream>
using namespace std;
#include "Warehouse.h"
#include <string>

int main(){
	setlocale(LC_ALL, "RU");
	Warehouse <int> intWarehouse;

	intWarehouse.addItem(100);
	intWarehouse.addItem(150);
	intWarehouse.addItem(200);

	cout << intWarehouse.getItem(0) << ", " << intWarehouse.getItem(1) << ", " << intWarehouse.getItem(2)<<endl;
	cout << "Всего чисел: " << intWarehouse.getTotalitems() << endl;

	Warehouse<string> stringWarehouse;
	stringWarehouse.addItem("lama");
	cout << "Строк: " << stringWarehouse.getItem(0)<<"\n";

}




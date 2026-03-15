#include "TransportUnit.h"

int DispatchCenter::totalVehiclesDispatched = 0;

void DispatchCenter::report()
{
	cout << "Колчисество транспорта: " << totalVehiclesDispatched << endl;
}

TransportUnit::TransportUnit(string b)
{
	DispatchCenter::totalVehiclesDispatched++;
	cout << "Название транспорта: " << b<< endl;
}

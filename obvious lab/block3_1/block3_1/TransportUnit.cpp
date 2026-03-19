#include "TransportUnit.h"



void DispatchCenter::report()
{
	cout << "Колчисество транспорта: " << totalVehiclesDispatched << endl;
}

TransportUnit::TransportUnit(string b)
{
	DispatchCenter::totalVehiclesDispatched++;
	cout << "Название транспорта: " << b<< endl;
}

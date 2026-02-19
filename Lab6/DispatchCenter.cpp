#include "DispatchCenter.h"

int DispatchCenter::totalVehiclesDispatched = 0;
void DispatchCenter::report() {
	cout << "¬сего обслужено транспортных средств: " << totalVehiclesDispatched << endl;
}
#include <iostream>;
#include"TransportUnit.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "RU");

	DispatchCenter::report();

	TransportUnit V1("kamaz");
	TransportUnit V2("HAVAL");

	DispatchCenter::report();
}
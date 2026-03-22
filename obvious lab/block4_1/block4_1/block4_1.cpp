#include <iostream>
#include "Bus.h"
#include "Tram.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "RU");

	Bus bus("Автобус", 120, "12A ", 50, "Dizel");
	bus.getStatus();
	bus.getInfo();
	cout << "\n";
	Tram tram("Травмвай", 80, "9C" , 120, 350);
	tram.getStatus();
	tram.getInfo();
}
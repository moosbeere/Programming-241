#include <iostream>
#include <string>
#include "vehicle.h"
using namespace std;



int main(){
	setlocale(LC_ALL, "RU");
	Vehicle automob("HYUNDAI", 300);
	automob.accelerate(100);
	automob.brake(90);
	automob.accelerate(190);
	automob.getStatus();
}
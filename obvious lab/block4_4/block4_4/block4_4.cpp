#include <iostream>
#include <vector>
#include "vehicle.h"
#include "PublicTransport.h"
#include"Bus.h"
#include"Tram.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    Bus bus("ЛиАЗ", 90, "5A", 80, "Дизель");
    Tram tram("Витязь", 80, "2I", 100, 550);

    bus.displayInfo();
    cout << endl;
    tram.displayInfo();
    cout << endl;
}
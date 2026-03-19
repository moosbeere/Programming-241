#include <iostream>      
#include "transport.h"   

int main() {
    
    TransportUnit* units[4];

    // Заполняем массив объектами производных классов
   
    units[0] = new Car();    
    units[1] = new Truck();  
    units[2] = new Car();    
    units[3] = new Truck();  

    double distance = 100.0; 

    // Цикл по всем элементам массива
    for (int i = 0; i < 4; ++i) {
       
        double toll = units[i]->calculateToll(distance);

       
        std::cout << "Плата для объекта " << i << ": " << toll << " у.е." << std::endl;
    }

    // Освобождаем память, выделенную под объекты
    for (int i = 0; i < 4; ++i) {
        delete units[i];  // Вызов delete через указатель на базовый класс
       
    }

    return 0;  
}

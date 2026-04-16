#include <iostream>
#include "DispatchCenter.h"
#include "Vehicle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "\n========== НАЧАЛО РАБОТЫ ==========\n" << endl;
    
 
    cout << "Вызов отчета до создания ТС:" << endl;
    DispatchCenter::report();
    
    cout << "\n========== РЕГИСТРАЦИЯ ТС ==========\n" << endl;
    
    
    Vehicle car1("Toyota", "Camry", "A123BC");
    Vehicle car2("Honda", "Civic", "B456DE");
    Vehicle car3("BMW", "X5", "C789FG");
    Vehicle truck1("Volvo", "FH16", "T001AA");
    Vehicle bus1("Mercedes", "Sprinter", "B002BB");
    
    cout << "\n========== ИНФОРМАЦИЯ О ТС ==========\n" << endl;
    
    //  Выводим информацию о каждом ТС
    car1.showInfo();
    car2.showInfo();
    car3.showInfo();
    truck1.showInfo();
    bus1.showInfo();
    
    cout << "\n========== ИТОГОВЫЙ ОТЧЕТ ==========\n" << endl;
    
    // Снова вызываем статический метод для проверки счетчика
    DispatchCenter::report();
    
    cout << "\n========== ДОПОЛНИТЕЛЬНАЯ ПРОВЕРКА ==========\n" << endl;
    
    
    cout << "Создаем еще одно ТС..." << endl;
    Vehicle car4("Tesla", "Model 3", "E004EE");
    
    cout << "\nОбновленный отчет:" << endl;
    DispatchCenter::report();
    
    cout << "\nНажмите Enter для выхода...";
    cin.get();
    
    return 0;
}

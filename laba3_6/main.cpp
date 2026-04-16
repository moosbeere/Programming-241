/*Задание 6: "Диспетчерская" (Статические члены класса)
Создайте класс DispatchCenter (Диспетчерский центр).
• Добавьте статическое поле: static int totalVehiclesDispatched; (общее количество обслуженных транспортных средств).
• Добавьте статический метод: static void report(), выводящий значение этого поля.
• В конструкторе Vehicle (или в отдельном методе register()) увеличивайте totalVehiclesDispatched.
• Цель: Понять назначение и использование статических полей и методов.*/
#include "Vehicle.h"
#include "DispatchCenter.h"

int main() {
    setlocale(LC_ALL, "ru");

    DispatchCenter::report();

    Vehicle v1("Lada");
    Vehicle v2("BMW");
    Vehicle v3("Mercedes");

    DispatchCenter::report();

    return 0;
}

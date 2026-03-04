#include <iostream>
#include <string>

// Диспетчерский центр
class DispatchCenter
{
public:
    // Общее количество "обслуженных" (зарегистрированных) транспортных средств
    static int totalVehiclesDispatched;

    // Отчёт по количеству
    static void report()
    {
        std::cout << "Total vehicles dispatched: "
                  << totalVehiclesDispatched << "\n";
    }
};

// Обязательное определение статического поля
int DispatchCenter::totalVehiclesDispatched = 0;

// Класс "Транспортное средство"
class Vehicle
{
private:
    std::string brand;

public:
    Vehicle(const std::string& brand)
        : brand(brand)
    {
        // Каждый созданный объект Vehicle регистрируется в диспетчерской
        DispatchCenter::totalVehiclesDispatched++;
    }

    void getStatus() const
    {
        std::cout << "Vehicle brand: " << brand << "\n";
    }
};

int main()
{
    std::cout << "Before creating vehicles:\n";
    DispatchCenter::report();

    Vehicle v1("Toyota");
    Vehicle v2("BMW");
    Vehicle v3("Volvo");

    std::cout << "\nAfter creating 3 vehicles:\n";
    DispatchCenter::report();

    {
        Vehicle v4("Mercedes");
        Vehicle v5("Audi");
        std::cout << "\nAfter creating 2 more vehicles in inner scope:\n";
        DispatchCenter::report();
    }

    std::cout << "\nAfter inner scope ends (objects destroyed, счётчик не уменьшается):\n";
    DispatchCenter::report();

    return 0;
}

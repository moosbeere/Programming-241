#include "transport.h"

int main() {
    std::cout << " Программа учета перевозок \n" << std::endl;
    
    // Пример 1: Грузовик с прицепом
    std::cout << "1. Создаем грузовик и отправляем в рейс" << std::endl;
    std::unique_ptr<TransportUnit> truck1(new Truck("Volvo", 0.35, 20000, 8000));
    AssignedRoute route1("Москва-Питер", 705, 25000, std::move(truck1));
    route1.showRoute();
    
    // Пример 2: Легковая машина
    std::cout << "\n2. Легковая машина для небольшого груза" << std::endl;
    auto car1 = std::make_unique<Car>("Toyota", 0.08, 500, "седан");
    AssignedRoute route2("Москва-Рязань", 196, 300, std::move(car1));
    route2.showRoute();
    
    // Пример 3: Машина не подходит по грузу
    std::cout << "\n3. Пытаемся загрузить слишком много" << std::endl;
    AssignedRoute route3("Москва-Тула", 193, 800,
                         std::make_unique<Car>("Lada", 0.09, 450, "хэтчбек"));
    route3.showRoute();
    
    // Пример 4: Перемещение маршрута
    std::cout << "\n4. Перемещаем маршрут (передача владения)" << std::endl;
    AssignedRoute route4 = std::move(route2);  // route2 теперь пустой
    
    std::cout << "Новый маршрут:" << std::endl;
    route4.showRoute();
    
    std::cout << "\nСтарый маршрут (пустой): ";
    if (route2.getTransport() == nullptr) {
        std::cout << "нет машины" << std::endl;
    }
    
    // Показываем автоматическое удаление
    std::cout << "\n5. Создаем временный маршрут в блоке" << std::endl;
    {
        auto temp = std::make_unique<Truck>("Kamaz", 0.45, 20000, 10000);
        AssignedRoute tempRoute("Тест", 50, 25000, std::move(temp));
        tempRoute.showRoute();
        std::cout << "Выход из блока..." << std::endl;
    }  // Здесь всё само уничтожится
    
    std::cout << "\nКонец программы" << std::endl;
    std::cout << "Все машины уничтожены автоматически!" << std::endl;
    
    return 0;
}

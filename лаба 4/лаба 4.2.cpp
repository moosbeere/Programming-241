#include <iostream>
#include <string>
#include <clocale>  // для setlocale

using namespace std;

class Weapon {
private:
    string name;    // название оружия
    int damage;     // наносимый урон
    float weight;   // вес оружия

public:
    // Конструктор с 3 параметрами
    Weapon(string weaponName, int weaponDamage, float weaponWeight) {
        name = weaponName;
        damage = weaponDamage;
        weight = weaponWeight;
        cout << "Создано оружие: " << name << endl;
    }
    
    // Конструктор без параметров
    Weapon() : Weapon("Стандартное оружие", 10, 2.5) {}
    
    // 1. Деструктор
    ~Weapon() {
        cout << "\n=== Деструктор вызывается ===" << endl;
        cout << "Удаляется оружие:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << endl;
        cout << "=== Объект удален ===\n" << endl;
    }
    
    // Методы для получения значений полей
    string getName() { return name; }
    int getDamage() { return damage; }
    float getWeight() { return weight; }
    
    // Метод для вывода информации об оружии
    void printInfo() {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }
    
    // 5. Метод для проверки, можно ли поднять оружие
    // Возвращает true, если вес оружия больше максимально допустимого
    bool isTooHeavy(float maxWeight) {
        return weight > maxWeight;
    }
    
    // 6. Метод, возвращающий суммарный вес текущего объекта и переданного
    float getTotalWeight(Weapon otherWeapon) {
        // 8. Используем перегруженный метод
        return getTotalWeight(otherWeapon.weight);
    }
    
    // 7. Перегрузка метода - принимает просто вес
    float getTotalWeight(float otherWeight) {
        return weight + otherWeight;
    }
};

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Альтернатива для Windows:
    // setlocale(LC_ALL, "Russian");
    
    cout << "=== Создание обычного объекта ===" << endl;
    // 2. Создаем обычный объект
    Weapon sword("Острый меч", 15, 3.2);
    
    cout << "\n=== Информация об обычном объекте ===" << endl;
    // Выводим переменные объекта
    sword.printInfo();
    
    // 5. Проверяем метод isTooHeavy
    cout << "\n=== Проверка веса оружия ===" << endl;
    float maxWeight = 3.0;
    cout << "Максимальный допустимый вес: " << maxWeight << " кг" << endl;
    if (sword.isTooHeavy(maxWeight)) {
        cout << "Это оружие слишком тяжелое!" << endl;
    } else {
        cout << "Это оружие можно поднять!" << endl;
    }
    
    cout << "\n=== Создание динамического объекта ===" << endl;
    // 3. Создаем динамический объект
    Weapon* bow = new Weapon("Длинный лук", 12, 1.8);
    
    cout << "\n=== Информация о динамическом объекте ===" << endl;
    // Выводим переменные динамического объекта
    bow->printInfo();
    
    // 9. Тестируем методы работы с весом
    cout << "\n=== Тестирование методов работы с весом ===" << endl;
    
    // Создаем еще одно оружие для теста
    Weapon axe("Тяжелый топор", 20, 4.5);
    
    // Тестируем метод getTotalWeight с объектом
    float totalWeight1 = sword.getTotalWeight(axe);
    cout << "Суммарный вес меча и топора: " << totalWeight1 << " кг" << endl;
    
    // Тестируем перегруженный метод getTotalWeight с числом
    float totalWeight2 = sword.getTotalWeight(2.5f);
    cout << "Суммарный вес меча и 2.5 кг: " << totalWeight2 << " кг" << endl;
    
    // Тестируем метод с динамическим объектом
    float totalWeight3 = bow->getTotalWeight(sword);
    cout << "Суммарный вес лука и меча: " << totalWeight3 << " кг" << endl;
    
    cout << "\n=== Удаление объектов ===" << endl;
    // 4. Удаляем динамический объект (деструктор вызовется)
    delete bow;
    
    cout << "\n=== Конец программы ===" << endl;
    // Деструктор для обычных объектов вызовется автоматически при выходе из области видимости
    
    return 0;
}
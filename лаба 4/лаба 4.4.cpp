#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// 10. Класс MyMath с статическими методами и полем
class MyMath {
private:
    static int callCount; // 10. Статическое поле для подсчета вызовов
    
public:
    // 9. Статические методы для математических операций
    static int Add(int a, int b) {
        callCount++; // 11. Инкрементируем счетчик вызовов
        return a + b;
    }
    
    static int Sub(int a, int b) {
        callCount++;
        return a - b;
    }
    
    static int Mult(int a, int b) {
        callCount++;
        return a * b;
    }
    
    static float Div(int a, int b) {
        callCount++;
        if (b != 0) {
            return static_cast<float>(a) / b;
        } else {
            cout << "Ошибка: деление на ноль!" << endl;
            return 0.0f;
        }
    }
    
    // Метод для получения количества вызовов
    static int getCallCount() {
        return callCount;
    }
};

// Инициализация статической переменной
int MyMath::callCount = 0;

// 5. Класс Characteristic
class Characteristic {
private:
    int strength; // сила
    
public:
    // Конструктор
    Characteristic(int str) : strength(str) {}
    
    // 7. Метод GetDamage
    int GetDamage(class Weapon& weapon); // прототип, так как Weapon объявлен позже
    
    // Геттер для силы
    int getStrength() const { return strength; }
    
    // Сеттер для силы
    void setStrength(int str) { strength = str; }
    
    // Объявляем класс Weapon дружественным (6)
    friend class Weapon;
};

// 1. Класс Weapon с приватными полями
class Weapon {
private:
    string name;    // название оружия
    int damage;     // наносимый урон
    float weight;   // вес оружия

public:
    // Конструкторы
    Weapon(string weaponName, int weaponDamage, float weaponWeight) {
        name = weaponName;
        damage = weaponDamage;
        weight = weaponWeight;
        cout << "Создано оружие: " << name << endl;
    }
    
    Weapon() : Weapon("Стандартное оружие", 10, 2.5) {}
    
    // Деструктор
    ~Weapon() {
        cout << "\n=== Деструктор вызывается ===" << endl;
        cout << "Удаляется оружие:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << endl;
        cout << "=== Объект удален ===\n" << endl;
    }
    
    // 2. GET-методы для всех полей
    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }
    
    // 3. SET-метод для наносимого урона
    void setDamage(int newDamage) { 
        damage = newDamage; 
        cout << "Урон оружия " << name << " изменен на: " << damage << endl;
    }
    
    // Метод для вывода информации об оружии
    void printInfo() const {
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }
    
    // Метод для проверки веса
    bool isTooHeavy(float maxWeight) const {
        return weight > maxWeight;
    }
    
    // Метод для получения суммарного веса
    float getTotalWeight(const Weapon& otherWeapon) const {
        return getTotalWeight(otherWeapon.weight);
    }
    
    // Перегрузка метода
    float getTotalWeight(float otherWeight) const {
        return weight + otherWeight;
    }
    
    // 6. Объявляем класс Characteristic дружественным
    friend class Characteristic;
};

// 7. Реализация метода GetDamage для Characteristic
int Characteristic::GetDamage(Weapon& weapon) {
    // Благодаря friend-отношению, имеем доступ к приватному полю damage
    return strength + weapon.damage;
}

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    cout << "=== Часть 1-4: Тестирование GET и SET методов класса Weapon ===\n" << endl;
    
    // Создаем оружие
    Weapon sword("Острый меч", 15, 3.2);
    
    // 4. Проверяем GET-методы
    cout << "Используем GET-методы:" << endl;
    cout << "Название: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    cout << "Вес: " << sword.getWeight() << endl;
    
    // 4. Проверяем SET-метод для урона
    cout << "\nИспользуем SET-метод для изменения урона:" << endl;
    sword.setDamage(25);
    cout << "Новый урон: " << sword.getDamage() << endl;
    
    cout << "\n=== Часть 5-8: Тестирование класса Characteristic ===\n" << endl;
    
    // 8. Создаем экземпляр Characteristic
    Characteristic heroStrength(20);
    cout << "Создан персонаж с силой: " << heroStrength.getStrength() << endl;
    
    // 8. Вызываем метод GetDamage
    int totalDamage = heroStrength.GetDamage(sword);
    cout << "Общий урон (сила + урон оружия): " << totalDamage << endl;
    
    // Изменяем силу и проверяем снова
    heroStrength.setStrength(30);
    totalDamage = heroStrength.GetDamage(sword);
    cout << "После увеличения силы до 30, общий урон: " << totalDamage << endl;
    
    cout << "\n=== Часть 9-13: Тестирование класса MyMath ===\n" << endl;
    
    // 12. Проверяем все 4 метода MyMath
    cout << "Результаты математических операций:" << endl;
    
    int a = 20, b = 5;
    
    cout << a << " + " << b << " = " << MyMath::Add(a, b) << endl;
    cout << a << " - " << b << " = " << MyMath::Sub(a, b) << endl;
    cout << a << " * " << b << " = " << MyMath::Mult(a, b) << endl;
    cout << a << " / " << b << " = " << MyMath::Div(a, b) << endl;
    
    // Еще несколько вызовов для теста
    cout << "\nДополнительные операции:" << endl;
    cout << "10 + 3 = " << MyMath::Add(10, 3) << endl;
    cout << "8 * 4 = " << MyMath::Mult(8, 4) << endl;
    
    // 13. Проверяем значение статической переменной
    cout << "\n=== Статистика вызовов ===" << endl;
    cout << "Количество вызовов методов MyMath: " << MyMath::getCallCount() << endl;
    cout << "(Ожидаемое значение: 6)" << endl;
    
    // Проверяем деструкторы
    cout << "\n=== Завершение программы ===" << endl;
    cout << "Объекты будут автоматически удалены..." << endl;
    
    return 0;
}
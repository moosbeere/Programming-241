#include <iostream> // Библиотека ввода-вывода
#include <string>   // Библиотека для работы со строками
using namespace std; // Использование стандартного пространства имен

class Weapon { // Объявление класса "Оружие"
private:
    string name;   // Название
    int damage;    // Урон
    double weight; // Вес
public:
    // Конструктор с параметрами: инициализирует поля и выводит сообщение
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {
        cout << "[Конструктор] Создано: " << name << endl;
    }

    // Конструктор по умолчанию: создает "Палку" через делегирование
    Weapon() : Weapon("Палка", 2, 1.0) {}

    // ДЕСТРУКТОР: вызывается автоматически при удалении объекта
    ~Weapon() {
        cout << "[Деструктор] Уничтожается: " << name
            << " (урон: " << damage
            << ", вес: " << weight << ")" << endl;
    }

    // Метод вывода информации (const — не меняет данные объекта)
    void printInfo() const {
        cout << "Оружие: " << name
            << " | Урон: " << damage
            << " | Вес: " << weight << endl;
    }

    // Проверка, превышает ли вес заданный предел
    bool isTooHeavy(double maxWeight) const {
        return weight > maxWeight;
    }

    // Перегрузка метода: сумма веса с другим объектом Weapon
    double totalWeight(const Weapon& other) const {
        return weight + other.weight;
    }

    // Перегрузка метода: сумма веса с числом типа double
    double totalWeight(double otherWeight) const {
        return weight + otherWeight;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // Поддержка кириллицы
    cout << "=== НАЧАЛО ПРОГРАММЫ ===" << endl << endl;

    // 1. Статический объект (в стеке): уничтожится сам в конце main
    Weapon sword("Клинок ночи", 42, 3.1);
    cout << "1. Sword создан: ";
    sword.printInfo();
    cout << endl;

    // 2. Динамический объект (в куче): создается через new, возвращает указатель
    Weapon* pAxe = new Weapon("Боевой топор", 55, 8.0);
    cout << "2. Axe создан: ";
    pAxe->printInfo(); // Доступ через стрелочку -> так как это указатель
    cout << endl;

    // 3. Вызов методов проверки веса
    cout << "3. Проверка веса:" << endl;
    cout << "   Sword слишком тяжел для 2.0? "
        << (sword.isTooHeavy(2.0) ? "ДА" : "нет") << endl;
    cout << "   Axe слишком тяжел для 9.0? "
        << (pAxe->isTooHeavy(9.0) ? "ДА" : "нет") << endl;
    cout << endl;

    // 4. Демонстрация перегрузки методов (разные параметры)
    cout << "4. Суммы весов:" << endl;
    cout << "   Sword + Axe = " << sword.totalWeight(*pAxe) << endl; // Передаем разыменованный указатель
    cout << "   Sword + 2.5 = " << sword.totalWeight(2.5) << endl;   // Передаем число
    cout << endl;

    // 5. Ручное удаление динамического объекта (обязательно для new!)
    cout << "5. Удаление динамического объекта Axe:" << endl;
    delete pAxe; // Вызывает деструктор для Axe
    cout << endl;

    // 6. Конец функции main
    cout << "6. Завершение main() - автоматически уничтожится sword" << endl;
    cout << "=== КОНЕЦ ПРОГРАММЫ ===" << endl;

    return 0; // После этой строки вызовется деструктор для sword
}
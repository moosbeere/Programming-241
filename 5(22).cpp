#include <iostream> // Подключаем библиотеку для вывода текста в консоль
#include <string>   // Подключаем библиотеку для работы со строками (тип string)
using namespace std; // Используем стандартное пространство имен, чтобы не писать std::

// 1. Базовый класс Weapon (Оружие)
class Weapon {
protected: // Спецификатор protected: поля видны в этом классе и во всех классах-наследниках
    string name;    // Переменная для названия оружия
    int damage;     // Переменная для базового урона
    double weight;  // Переменная для веса
public:
    // Конструктор: принимает параметры и инициализирует поля через список инициализации
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {
    }

    // Конструктор по умолчанию: создает "Палку" с уроном 2 и весом 1.0
    Weapon() : Weapon("Палка", 2, 1.0) {}

    // Обычные геттеры для получения значений приватных/защищенных полей
    string getName() const { return name; } // Получить имя
    double getWeight() const { return weight; } // Получить вес

    // Ключевое слово virtual: позволяет переопределить этот метод в классах-наследниках
    virtual int getDamage() const { return damage; }

    // 4. Перегрузка оператора "больше" (>) для сравнения двух объектов Weapon по урону
    bool operator>(const Weapon& other) const {
        return getDamage() > other.getDamage(); // Сравнивает результат метода getDamage текущего объекта и другого
    }

    // Перегрузка оператора "меньше" (<) для сравнения по урону
    bool operator<(const Weapon& other) const {
        return getDamage() < other.getDamage(); // Вызывает getDamage(), что важно для корректного учета магии
    }

    // Виртуальный метод для вывода информации, который можно будет дополнить в наследниках
    virtual void printInfo() const {
        cout << "Название оружия: " << name << endl; // Печать имени
        cout << "Наносимый урон: " << getDamage() << endl; // Печать урона (вызовется нужная версия метода)
        cout << "Вес оружия: " << weight << endl; // Печать веса
    }
};

// 2. Дочерний класс MagWeapon (Магическое оружие), наследуется от Weapon
class MagWeapon : public Weapon {
    int extraDamage; // Дополнительное приватное поле только для магического урона
public:
    // Конструктор: вызывает конструктор родителя (Weapon) и инициализирует свое поле extraDamage
    MagWeapon(const string& n, int d, double w, int extra)
        : Weapon(n, d, w), extraDamage(extra) {
    }

    // override: говорит компилятору, что мы намеренно переопределяем виртуальный метод родителя
    int getDamage() const override {
        return damage + extraDamage; // Магический урон — это сумма базового и дополнительного
    }

    // Переопределение метода вывода информации для магического оружия
    void printInfo() const override {
        cout << "Название маг. оружия: " << name << endl; // Печать имени (доступно благодаря protected)
        cout << "Базовый урон: " << damage << endl;       // Печать базы
        cout << "Доп. магический урон: " << extraDamage << endl; // Печать бонуса
        cout << "Общий урон: " << getDamage() << endl;    // Печать суммы через нашу новую формулу
        cout << "Вес: " << weight << endl;                // Печать веса
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль для корректного отображения кириллицы

    // 3. Создаем объекты обычного и магического оружия
    Weapon sword("Клинок", 20, 2.5); // Обычный меч (урон 20)
    MagWeapon fireSword("Огненный меч", 18, 2.6, 15); // Магический меч (база 18 + бонус 15 = 33)

    cout << "=== Обычное оружие ===" << endl;
    sword.printInfo(); // Вызов базовой версии printInfo
    cout << endl;

    cout << "=== Магическое оружие ===" << endl;
    fireSword.printInfo(); // Вызов переопределенной версии printInfo
    cout << endl;

    // Демонстрация работы виртуального метода getDamage()
    cout << "Урон обычного меча: " << sword.getDamage() << endl;
    cout << "Урон магического меча: " << fireSword.getDamage() << endl;
    cout << endl;

    // 5. Проверка перегруженных операторов сравнения
    cout << "--- Проверка сравнения ---" << endl;

    // Используем оператор ">". Хотя fireSword — MagWeapon, он также является и Weapon
    if (fireSword > sword) { // 33 > 20 — истина
        cout << fireSword.getName() << " сильнее, чем " << sword.getName() << endl;
    }
    else {
        cout << sword.getName() << " сильнее, чем " << fireSword.getName() << endl;
    }

    // Создаем кинжал для тестов
    Weapon dagger("Кинжал", 10, 1.0);
    if (dagger < sword) { // 10 < 20 — истина
        cout << dagger.getName() << " слабее, чем " << sword.getName() << endl;
    }

    // Сравнение обычного предмета с магическим
    if (dagger < fireSword) { // 10 < 33 — истина
        cout << dagger.getName() << " слабее, чем " << fireSword.getName() << endl;
    }

    // Еще один магический предмет (урон 6 + 8 = 14)
    MagWeapon shadowDagger("Теневой кинжал", 6, 1.2, 8);
    if (shadowDagger > dagger) { // 14 > 10 — истина
        cout << shadowDagger.getName() << " сильнее, чем " << dagger.getName() << endl;
    }

    // Сравнение двух магических предметов разной силы
    if (shadowDagger < fireSword) { // 14 < 33 — истина
        cout << shadowDagger.getName() << " слабее, чем " << fireSword.getName() << endl;
    }

    return 0; // Завершение программы
}
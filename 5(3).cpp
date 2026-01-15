#include <iostream> // Подключаем библиотека ввода-вывода
#include <string>   // Подключаем библиотеку для работы со строками
using namespace std; // Используем стандартное пространство имен

// 1. Абстрактный класс Weapon — фундамент для всех видов оружия
class Weapon {
protected: // Поля доступны наследникам, но закрыты для внешнего кода
    string name;    // Имя оружия
    int damage;     // Базовый урон
    double weight;  // Вес оружия
public:
    // Конструктор с параметрами: инициализирует общие свойства
    Weapon(const string& n, int d, double w)
        : name(n), damage(d), weight(w) {
    }

    // Конструктор по умолчанию (делегирует создание основному конструктору)
    Weapon() : Weapon("Палка", 2, 1.0) {}

    // Геттеры для получения данных (const гарантирует, что метод не меняет объект)
    string getName() const { return name; }
    virtual int getDamage() const { return damage; } // Виртуальный метод урона
    double getWeight() const { return weight; }

    // ЧИСТО ВИРТУАЛЬНАЯ ФУНКЦИЯ: делает класс абстрактным (= 0)
    // Она заставляет всех наследников реализовать свою версию атаки
    virtual void Attack() const = 0;

    // Виртуальный метод вывода информации
    virtual void printInfo() const {
        cout << "Название оружия: " << name << endl;
        cout << "Наносимый урон: " << getDamage() << endl;
        cout << "Вес оружия: " << weight << endl;
    }
};

// 2. Класс MagWeapon — наследник, реализующий магическую атаку
class MagWeapon : public Weapon {
    int extraDamage; // Дополнительный магический бонус к урону
public:
    // Конструктор: передает общие параметры в Weapon и сохраняет бонус
    MagWeapon(const string& n, int d, double w, int extra)
        : Weapon(n, d, w), extraDamage(extra) {
    }

    // Переопределение урона: возвращает сумму базового и магического
    int getDamage() const override {
        return damage + extraDamage;
    }

    // Переопределение печати: выводит расширенную информацию
    void printInfo() const override {
        cout << "Название маг. оружия: " << name << endl;
        cout << "Базовый урон: " << damage << endl;
        cout << "Доп. магический урон: " << extraDamage << endl;
        cout << "Общий урон: " << getDamage() << endl;
        cout << "Вес: " << weight << endl;
    }

    // Реализация чисто виртуальной функции родителя
    void Attack() const override {
        cout << "Атакуем магическим оружием" << endl;
    }
};

// 5. Класс SingleUseWeapon — оружие, которое можно использовать один раз
class SingleUseWeapon : public Weapon {
    // Поле used помечено как mutable, чтобы его можно было менять в const-методах
    mutable bool used;
public:
    // Конструктор: по умолчанию оружие еще не использовано (false)
    SingleUseWeapon(const string& n, int d, double w)
        : Weapon(n, d, w), used(false) {
    }

    // Логика атаки с проверкой состояния
    void Attack() const override {
        if (used) { // Если флаг true — атака невозможна
            cout << "Оружие уже было использовано" << endl;
        }
        else { // Если false — атакуем и помечаем как использованное
            cout << "Атакуем одноразовым оружием" << endl;
            used = true; // Изменение разрешено благодаря mutable
        }
    }

    // Проверка статуса (использовано или нет)
    bool isUsed() const { return used; }
    // Метод для "перезарядки" оружия
    void reset() { used = false; }
};

// 9. ШАБЛОННЫЙ КЛАСС: позволяет хранить два любых объекта в "руках"
template<typename TLeft, typename TRight>
class DualWeaponHolder {
private:
    TLeft leftWeapon;   // Объект в левой руке (тип TLeft определится позже)
    TRight rightWeapon; // Объект в правой руке (тип TRight определится позже)
public:
    // Конструктор шаблона
    DualWeaponHolder(const TLeft& left, const TRight& right)
        : leftWeapon(left), rightWeapon(right) {
    }

    // Методы получения объектов
    TLeft getLeft() const { return leftWeapon; }
    TRight getRight() const { return rightWeapon; }

    // Методы замены объектов
    void setLeft(const TLeft& left) { leftWeapon = left; }
    void setRight(const TRight& right) { rightWeapon = right; }
};

// Главная точка входа
int main() {
    setlocale(LC_ALL, "Russian"); // Включаем русский язык в консоли

    // 3. ПРОВЕРКА: Weapon base("Base", 5, 2.0); — вызовет ошибку, класс абстрактный!

    // Создаем магический посох и атакуем им
    MagWeapon fireSword("Огненный посох", 10, 2.0, 8);
    fireSword.Attack();

    // Создаем гранату и пробуем атаковать дважды
    SingleUseWeapon bomb("Граната", 60, 0.7);
    bomb.Attack(); // Первая атака — успех
    bomb.Attack(); // Вторая атака — выведет сообщение об использовании

    // ПРОВЕРКА ШАБЛОНА: создаем держатель для посоха и гранаты
    DualWeaponHolder<MagWeapon, SingleUseWeapon> holder(fireSword, bomb);
    cout << "В левой руке: " << holder.getLeft().getName() << endl;
    cout << "В правой руке: " << holder.getRight().getName() << endl;

    // Меняем предмет в левой руке на ледяной посох
    MagWeapon iceStaff("Ледяной посох", 7, 2.1, 12);
    holder.setLeft(iceStaff);
    cout << "Новое оружие слева: " << holder.getLeft().getName() << endl;

    // ПРОВЕРКА ШАБЛОНА С ЧИСЛАМИ: доказывает универсальность шаблона
    DualWeaponHolder<int, int> idHolder(101, 205);
    cout << "ID игрока 1: " << idHolder.getLeft() << endl;
    cout << "ID игрока 2: " << idHolder.getRight() << endl;
    idHolder.setRight(404); // Замена значения справа
    cout << "Обновленный ID 2: " << idHolder.getRight() << endl;

    return 0; // Завершение программы
}
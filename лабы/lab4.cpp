#include <iostream>
#include "weapon.h"

using namespace std;

// 5. Класс характеристик с полем силы
class Characteristic
{
private:
    int strength; // сила персонажа

public:
    explicit Characteristic(int s)
        : strength(s)
    {
    }

    // 7. Функция, принимающая оружие и возвращающая сумму силы и урона
    int GetDamage(const Weapon& weapon) const
    {
        // Доступ к приватному полю damage возможен благодаря friend class Characteristic
        return strength + weapon.damage;
    }
};

// 9. Класс с четырьмя статическими методами и счётчиком вызовов
class MyMath
{
public:
    static int callCount;

    static int Add(int a, int b)
    {
        ++callCount;
        return a + b;
    }

    static int Sub(int a, int b)
    {
        ++callCount;
        return a - b;
    }

    static int Mult(int a, int b)
    {
        ++callCount;
        return a * b;
    }

    static double Div(double a, double b)
    {
        ++callCount;
        if (b == 0.0)
        {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 0.0;
        }
        return a / b;
    }
};

// 10. Определение статического поля
int MyMath::callCount = 0;

int main()
{
    // 2. Создаём объект оружия (статический объект на стеке)
    Weapon sword("Меч рыцаря", 50, 4.5f, WeaponType::TWOHANDED);

    cout << "Статический объект weapon (sword):" << endl;
    sword.print();

    // 3. Создаём динамический объект оружия
    Weapon* bow = new Weapon("Боевой лук", 30, 2.0f, WeaponType::BOW);
                              // new Weapon(...) - динамическое выделение памяти в куче (heap)
                              // создаёт объект Weapon и возвращает указатель на него
                              // Weapon* - указатель на объект типа Weapon
    cout << "\nДинамический объект weapon (bow):" << endl;
    bow->print();             // bow->print() - доступ к методу через указатель
                              // -> это оператор разыменования указателя с доступом к члену
                              // эквивалентно (*bow).print()

    // 5. Проверяем метод isTooHeavy
    float maxWeightForHero = 3.0f;
    cout << "\nМаксимально допустимый вес для героя: " << maxWeightForHero << " кг" << endl;
    cout << "Может ли герой поднять меч? "
         << (sword.isTooHeavy(maxWeightForHero) ? "Нет, слишком тяжёлый" : "Да, может") << endl;
                              // тернарный оператор ? : - условное выражение
                              // если условие true, возвращает первое значение, иначе второе
                              // здесь используется для выбора текста в зависимости от результата
    cout << "Может ли герой поднять лук? "
         << (bow->isTooHeavy(maxWeightForHero) ? "Нет, слишком тяжёлый" : "Да, может") << endl;

    // 6–8. Проверяем методы суммы веса
    Weapon axe("Тяжёлый топор", 70, 6.0f, WeaponType::TWOHANDED);
    cout << "\nОружие axe:" << endl;
    axe.print();

    float total1 = sword.totalWeight(axe);          // через версию, принимающую объект
    float extraWeight = 1.5f;
    float total2 = sword.totalWeight(extraWeight);  // через версию, принимающую число

    cout << "\nСуммарный вес sword + axe = " << total1 << " кг" << endl;
    cout << "Суммарный вес sword + " << extraWeight << " кг = " << total2 << " кг" << endl;

    // 2–4. Проверка GET/SET-методов
    cout << "\nПроверка GET/SET методов для Weapon:" << endl;
    cout << "Имя: " << sword.getName()
         << ", урон: " << sword.getDamage()
         << ", вес: " << sword.getWeight() << " кг" << endl;

    sword.setDamage(60);
    cout << "После изменения урона setDamage(60): " << sword.getDamage() << endl;

    // 8. Проверка класса Characteristic и метода GetDamage
    Characteristic heroStrength(25);  // explicit конструктор предотвращает неявные преобразования
                                      // без explicit можно было бы написать Characteristic h = 25;
    int fullDamage = heroStrength.GetDamage(sword);
                                      // GetDamage имеет доступ к приватному полю weapon.damage
                                      // благодаря friend class Characteristic в определении Weapon
    cout << "\nУрон героя с мечом (сила + урон оружия): " << fullDamage << endl;

    // 11–13. Проверка класса MyMath и счётчика вызовов
    cout << "\nПроверка MyMath:" << endl;
    int a = 10;
    int b = 4;

    int sum  = MyMath::Add(a, b);
    int diff = MyMath::Sub(a, b);
    int prod = MyMath::Mult(a, b);
    double quot = MyMath::Div(a, b);

    cout << "Add(" << a << ", " << b << ") = " << sum << endl;
    cout << "Sub(" << a << ", " << b << ") = " << diff << endl;
    cout << "Mult(" << a << ", " << b << ") = " << prod << endl;
    cout << "Div(" << a << ", " << b << ") = " << quot << endl;

    cout << "Количество вызовов статических методов MyMath::callCount = "
         << MyMath::callCount << endl;

    // 4. Не забываем удалить динамический объект, чтобы увидеть вызов деструктора
    delete bow;              // delete вызывает деструктор объекта, затем освобождает память
                              // важно: каждый new должен иметь соответствующий delete
    bow = nullptr;            // обнуляем указатель для безопасности
                              // nullptr - специальное значение "пустой указатель" (C++11)
                              // предотвращает случайное использование после delete

    cout << "\nЗавершение программы, сейчас будут вызваны деструкторы статических объектов." << endl;

    return 0;
}



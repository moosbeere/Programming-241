#include <iostream>
#include "weapon.h"

using namespace std;

// Функция для текстового представления типа
string weaponTypeToString(WeaponType type) {
    switch (type) {
    case ONEHANDED: return "Одноручное";
    case TWOHANDED: return "Двуручное";
    case BOW: return "Лук";
    case CROSSBOW: return "Арбалет";
    default: return "Неизвестно";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    // 3. Проверка, что нельзя создать экземпляр абстрактного класса
    // Weapon weapon("Меч", 10, 2.0f, ONEHANDED);  // Ошибка 

    // 4. Создание экземпляра магического оружия
    MagicWeapon magicSword("Волшебный клинок", 30, 2.8f, ONEHANDED, 10);
    cout << "\nМагическое оружие создано: " << magicSword.getName();
    cout << "\nУрон: " << magicSword.getDamage() << " (30 базовый + 10 магический)";

    // Вызов метода Attack
    cout << "\nАтака магическим оружием: ";
    magicSword.Attack();

    cout << "\n\n=== Пункт 5-8: Одноразовое оружие ===" << endl;

    // 8. Создание экземпляра одноразового оружия
    DisposableWeapon throwingKnife("Метательный нож", 25, 0.8f, ONEHANDED);
    cout << "\nОдноразовое оружие создано: " << throwingKnife.getName();
    cout << "\nИспользовано? " << (throwingKnife.isUsed() ? "Да" : "Нет");

    // Дважды вызываем Attack
    cout << "\n\nПервая атака: ";
    throwingKnife.Attack();
    cout << "Использовано? " << (throwingKnife.isUsed() ? "Да" : "Нет");

    cout << "\n\nВторая атака: ";
    throwingKnife.Attack();
    cout << "Использовано? " << (throwingKnife.isUsed() ? "Да" : "Нет");

    cout << "\n\n=== Пункт 9-11: Шаблон класса DualWield ===" << endl;

    // 11. Проверка с типами оружия
    MagicWeapon leftMagic("Магический щит", 5, 3.0f, ONEHANDED, 2);
    DisposableWeapon rightDisposable("Запасной кинжал", 15, 1.0f, ONEHANDED);

    DualWield<MagicWeapon, DisposableWeapon> warrior(leftMagic, rightDisposable);

    cout << "\nВоин с двумя видами оружия:";
    cout << "\nЛевая рука: " << warrior.getLeft().getName();
    cout << "\nПравая рука: " << warrior.getRight().getName();

    // Атака обоим оружием
    cout << "\n\nАтака воина:";
    warrior.getLeft().Attack();
    warrior.getRight().Attack();
    cout << "Еще раз правая рука: ";
    warrior.getRight().Attack();  // Должно показать, что уже использовано

    // 11. Проверка с целыми типами (например, ID оружия)
    cout << "\n=== Использование шаблона с простыми типами ===" << endl;

    DualWield<int, int> simpleWarrior(101, 202);
    cout << "\nID оружия воина:";
    cout << "\nЛевая рука (ID): " << simpleWarrior.getLeft();
    cout << "\nПравая рука (ID): " << simpleWarrior.getRight();

    // Изменяем оружие
    simpleWarrior.setLeft(303);
    simpleWarrior.setRight(404);
    cout << "\nПосле смены оружия:";
    cout << "\nЛевая рука (ID): " << simpleWarrior.getLeft();
    cout << "\nПравая рука (ID): " << simpleWarrior.getRight();

    cout << "\n\n=== Полиморфизм через указатели ===" << endl;

    // Создаем массив указателей на Weapon
    Weapon* arsenal[2];
    arsenal[0] = new MagicWeapon("Посох мага", 15, 2.5f, TWOHANDED, 20);
    arsenal[1] = new DisposableWeapon("Священный гранатомет", 100, 5.0f, TWOHANDED);

    cout << "\nАрсенал атакует:";
    for (int i = 0; i < 2; i++) {
        cout << "\n" << arsenal[i]->getName() << ": ";
        arsenal[i]->Attack();  // Полиморфизм!
    }

    // Очищаем память
    for (int i = 0; i < 2; i++) {
        delete arsenal[i];
    }

    cout << "\n=== Проверка завершена успешно! ===" << endl;

    return 0;
}
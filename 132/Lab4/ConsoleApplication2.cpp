// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"
#include "AIMonster.h"
#include "Move.h"
#include "FlyMonster.h"
using namespace std;

int Monster::counter = 0;

struct Item {
    string name;
    string description;
    float price = 0;
};

void printItem(Item& item);

bool operator > (FlyMonster m1, FlyMonster m2) {
    return m1.getHealth() > m2.getHealth();
}

bool operator < (FlyMonster m1, FlyMonster m2) {
    return m1.getHealth() < m2.getHealth();
}

int main()
{
    //operator
    FlyMonster m1("Fly1", 6, 4, 4, 4);
    FlyMonster m2("Fly1", 8, 4, 4, 4);
    //cout << (m1 > m2) << endl;
    FlyMonster m3 = m1 + m2;
    //m3.print();
    //string s = m3; ошибка неявного преобразования к типу данных string в результате добавления ключевого слова explicit в заголовочном файле класса Monster
    //cout << s << endl;
    //cout << string(m1) << endl;
    cout << (m1 == m2) << endl;

    //virtual
    FlyMonster virtualFly("Virtual", 3, 6, 8, 6);
    //virtualFly.print();
    Monster* pmonsters[] = { new Monster(), new FlyMonster(), new FlyMonster() };
    for(Monster* m : pmonsters) {
        m->print();
    }

    //extends
    FlyMonster fly;
    //fly.setHealth(6); ошибка после изменения модификатора доступа на protected
    FlyMonster dragon("Dragon", 60, 100, 20, 5);
    dragon.fly();
    cout << dragon.getHealth() << endl;

    setlocale(LC_ALL, "RU");
    //structure
    Item item1;
    item1.name = "Зелье здоровья";
    item1.description = "Восстанавливает 50 единиц здоровья";
    item1.price = 20;
    printItem(item1);

    Item item2 = { "Зелье маны","Восстанавливает 50 единиц маны", 15 };
    printItem(item2);   
    //enum
    Move::move(Direction::NORTH);
    Move::move(Direction::EAST);
    Move::move(Direction::WEST);
    Move::move(Direction::SOUTH);
    //Move::move(5); ошибка на уровне компиляции

    Monster M = Monster("Goblin", 5, 7, 3);
    Monster M2 = Monster("attackM", 4, 6, 2);
    M.attack(M2);
    cout << M2.getName() << " " << M2.getHealth() << " " << M2.getDamage() << endl;

    M.applyDamage(3);
    M.applyDamage();
    M.recovery();
    cout << M.getName() << " " << M.getHealth() << " " << M.getDamage() << endl;
    cout << M.getLevel() << endl;

    Monster Mset = Monster("Setter", 4, 8, 9);
    //Mset.setHealth(-2);
    cout << Mset.getName() << " " << Mset.getHealth() << " " << Mset.getDamage() << endl;
    test(Mset);

    AIMonster ai;
    ai.move(&Mset);
    Mset.applyDamage(50);
    ai.move(&Mset);

    //static property and method
    cout << "\nMonster counter = " << Monster::counter << endl;
    Monster::resetCounter();
    cout << "Monster counter = " << Monster::counter << endl;

}

//реализация дружественного метода
void test(const Monster& m) {
    cout << m.name << endl;
    cout << m.health << endl;
}

void printItem(Item& item) {
    cout << "Name: " << item.name << endl;
    cout << "Description: " << item.description << endl;
    cout << "Price: " << item.price << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

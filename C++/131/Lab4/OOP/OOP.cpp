// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"
#include "AIMonster.h"
using namespace std;

int Monster::counter = 0;
void test(const Monster& m) {
    //cout << m.name << endl;
    cout << m.getHealth() << endl;
}

int main()
{

    //static
    Monster m9;
    Monster m2;
    Monster m3;
    cout << Monster::counter << endl;
    Monster::resetCounter();
    cout << Monster::counter << endl;

    
    //friend
    Monster m6;
    //test(m6);

    AIMonster ai;
    ai.move(&m6);
    m6.applyDamage(50);
    ai.move(&m6);


    setlocale(LC_ALL, "RU");
    Monster m;
    Monster m1("Monster", 6, 8, 2);
    m.attack(m1);
    //m.warning(); скрытый protected метод

    cout << m.getHealth() << endl;
    m.setHealth(-10);
    //cout << m.health << endl; Ошибка обращения к приватному свойству класса

    //m.applyDamage();
    //cout << m.getLevel() << endl;
    //cout << m.health << endl;
    //m.recovery();
    //cout << m.health << endl;


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

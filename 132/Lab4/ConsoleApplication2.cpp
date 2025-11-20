// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"
#include "AIMonster.h"
using namespace std;

int Monster::counter = 0;

int main()
{
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
    Mset.setHealth(-2);
    cout << Mset.getName() << " " << Mset.getHealth() << " " << Mset.getDamage() << endl;
    test(Mset);

    AIMonster ai;
    ai.move(&Mset);
    Mset.applyDamage(50);
    ai.move(&Mset);
    cout << "\nMonster counter = " << Monster::counter << endl;
    Monster::resetCounter();
    cout << "Monster counter = " << Monster::counter << endl;

}

//реализация дружественного метода
void test(const Monster& m) {
    cout << m.name << endl;
    cout << m.health << endl;
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

// Lab5 (Template).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef int Count; // псевдоним типа данных int
template <typename T>
//template <typename X, typename Y>


class Player {
private:
    T health;

public:
    Player(T health) : health(health) {}
    T getHealth() {
        return health;
    }
    void setHealth(T health) {
        this->health = health;
    }

    Player operator +(Player p) {
        return Player(p.getHealth() + health);
    }
    void test(Player* p) {
        if (p == nullptr) return;
        std::cout << p->getHealth() << std::endl;
    }
};

template <typename TN>

TN add(TN a, TN b) {
    return a + b;
}


typedef int Coord;

class Rectangle {
    Coord x;
    Coord y;
};

int main()
{
    Count i = 5;

    Player<int> p(100);
    p.setHealth(50);
    std::cout << p.getHealth() << "\n";

    Player<double> f2(0.7);
    f2.setHealth(0.89);
    std::cout << f2.getHealth() << "\n";

    Player<double> f3(0.7);

    std::cout << (f2 + f3).getHealth() << std::endl;
    std::cout << add(f2,f3).getHealth() << std::endl;
    std::cout << add(5, 7) << std::endl;

    p.test(nullptr);
    f2.test(&f3);
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

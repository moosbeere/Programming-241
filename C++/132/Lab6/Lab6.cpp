// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PlayerException.h"

class Player {
private:
    int health;

public:
    Player(int health) {
        //if (health < 0) throw std::logic_error("Health < 0");
        //else if (health > 100) throw std::range_error("Health > 100");
        //else if (health == 0) throw std::exception();
        if (health < 0) throw PlayerException(PlayerError::NEGATIVE);
        else if (health > 100) PlayerException(PlayerError::BIG);
        else if (health == 0) PlayerException(PlayerError::ZERO);
    }
    int getHealth() {
        return health;
    }
};

int main()
{
    try {
        //Player p1(2000);
        //Player p1(-10);
        Player p1(0);
        std::cout << "Health: " << p1.getHealth() << "\n";
    }
    catch (std::logic_error err){
           std::cout << "logic error: " << err.what();
    }
    catch (std::range_error err) {
        std::cout << "range error: " << err.what();
    }
    catch (std::exception err) {
        std::cout << "exception: " << err.what();
    }
     


    /*try {
        int x = 5;
        int y = 0;
        if (y == 0) throw "Exception: division by zero!";
        std::cout << "x / y = " << x / y << "\n";
    }
    catch(const char* msg){
        std::cout << msg << "\n";
    }*/
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

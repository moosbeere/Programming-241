#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;


struct Player {
    int id;             
    string login;       
    string password;    

    void printInfo() const {
        cout << "=== Информация об игроке ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Логин: " << login << endl;
        cout << "Пароль: " << password << endl;
        cout << "===========================" << endl;
    }
};

#endif
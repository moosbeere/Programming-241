#pragma once
#include <iostream>
using namespace std;

// 1. Перечисление типов оружия
enum class TypeOrugie {
    ONEHANDED, // одноручное
    TWOHANDED, // двуручное
    BOW, // лук
    CROSSBOW // арбалет
};


class Orugie
{
private:
    string name;
    int uron;
    TypeOrugie type; 

public:
    Orugie();
    Orugie(string n, int u, TypeOrugie t);

    TypeOrugie GetType();
    string GetName();
    int GetUron();


    string GetTypeString();
};


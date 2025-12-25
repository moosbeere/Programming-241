#pragma once
#include <iostream>
using namespace std;

// 4. Структура игрока
struct Igrok {
    int id;
    string login;
    string password;
    
    // 5. Функция для вывода всех данных в консоль
    void def();
};
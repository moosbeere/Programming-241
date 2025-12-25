#pragma once
#include "Orugie.h"
#include <iostream>

// 7. Дочерний класс для магического оружия
class MagicOrugie : public Orugie {
private:
    int DopUron;  // 8. дополнительный урон

public:
    // 9. Конструкторы
    MagicOrugie();
    MagicOrugie(string n, int d, TypeOrugie t, int du);


    // 10. GET-метод для дополнительного урона
    int GetDopUron();

};

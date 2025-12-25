#pragma once
#include "Orugie.h"
#include <iostream>

class MagicOrugie : public Orugie {
private:
    int DopUron;  

public:
    
    MagicOrugie();
    MagicOrugie(string n, int d, TypeOrugie t, int du);


    int GetDopUron();

};

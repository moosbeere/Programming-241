#include <iostream>
#include "Orugie.h"
#include "MegicOrugie.h"
#include "Igrok.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Orugie mech("Меч", 15, TypeOrugie::ONEHANDED);
    cout << mech.GetName() << " " << mech.GetUron() << " " << mech.GetTypeString() << endl;

    Igrok igrok1;
    igrok1.id = 1;
    igrok1.login = "hero123";
    igrok1.password = "securePass";
    igrok1.def();

    MagicOrugie palochka("Волшебная палочка", 8, TypeOrugie::TWOHANDED, 20);
    cout << palochka.GetName() << " " << palochka.GetUron() << " " << palochka.GetTypeString() << " " << palochka.GetDopUron() << endl;
}

#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int a = 150;
    float b = 15.933f;
    uint8_t c = 250;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << static_cast<int>(c) << endl;

    uint8_t day = 8;
    string month = "Июль";
    uint16_t year = 2006;

    cout << "Моя дата рождения: " << static_cast<int>(day) << " " << month << " " << year << " года" << endl;

    const float PI = 2.3f;
    const string OS = "WINDOWS";

    cout << PI << " " << OS << endl;

    return 0;
}



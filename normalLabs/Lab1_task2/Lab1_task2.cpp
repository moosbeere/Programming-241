#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int first = 150;
    float second = 15.933;
    short third = 250;
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
    cout << "third = " << third << endl;

    int day = 26;
    int month = 7;
    int year = 2006;
    cout << "Моя дата рождения: " << day << " " << setw(2) << setfill('0') << month << " " << year << " года";

    const float lastone = 2.3;
    const string lasttwo = "WINDOWS";
    cout << endl << lastone << " " << lasttwo;
}

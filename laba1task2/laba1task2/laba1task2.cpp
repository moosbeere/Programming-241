#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int a = 150;
    float b = 15.933;
    short c = 250;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;

    int day = 23;
    string month = "july";
    int year = 2006;
    cout << "Моя дата рожения : " << day << "\t" << month << "\t" << year << "\n";

    float const d = 2.3;
    string const win = "WINDOWS";

    cout << d << " " << win << endl;
}

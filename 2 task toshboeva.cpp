
#include <iostream>
#include <string> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задание 1
    int number1 = 150;

    // Задание 2
    float number2 = 15.933f; 

    // Задание 3
    unsigned char number3 = 250; 

    // Задание 4
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;
    cout << "number3 = " << (int)number3 << endl; // переводим char в int для красивого вывода

    // Задание 5
    int day = 15; 
    string month = "сентября"; 
    int year = 2003;
    // Задание 6
    cout << "Моя дата рождения: " << day << " " << month << " " << year << " года" << endl;

    // Задание 7
    const float CONST_NUMBER = 2.3f;    
    const string CONST_OS = "WINDOWS";  

    // Задание 8
    cout << CONST_NUMBER << " " << CONST_OS << endl;

    return 0;
}
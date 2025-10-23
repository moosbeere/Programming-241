#include <iostream>
#include <string>
#include <locale>
#include "Windows.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s1;
    cout << "Введите строчку: ";
    cin >> s1;
    cout << endl << s1 << endl;
    if (s1.length() >= 4) {
        cout << s1.substr(1, 3) << endl;
    }
    else {
        cout << "Строка слишком короткая!" << endl;
    }
    int pos = s1.find('а');
    cout << pos << endl;
    if (pos == string::npos) {
        cout << "Символ а не найден!" << endl;
    }
    else {
        cout << "Символ а находится под индексом: " << pos << endl;
    }
    
}
#include <iostream>
#include <string>
using namespace std;

void print(string s)
{
    cout << s << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string name;
    cout << "Введите строку" << endl;
    cin >> name;
    //print(name.substr(1, 3));
    int index = name.find("a");
    if (index == -1) {
        cout << "Символа a не найдено";
    }
    else {
        cout << index + 1;
    }
}

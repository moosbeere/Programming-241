#include <iostream>
#include <string>
#include <regex>
using namespace std;


bool proverka(string nam) {
    regex reg("^[A-Z][a-zA-Z]{2,32}");
    return regex_search(nam, reg);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;
    cout << "" << endl;
    cin >> name;
    cout << proverka(name);
}

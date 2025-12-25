#include <iostream>
#include <string>
#include <regex>
using namespace std;


bool proverka(string nam) {
    regex reg("^[A-Z][a-zA-Z]{2,32}");
    return regex_search(nam, reg);
}
void emailProverka(string em) {
    regex reg("[а-яa-zA-Z0-9_.]+@[а-яa-zA-Z0-9_]+\.[а-яa-zA-Z0-9]{2,}");
    smatch matches;
    while (regex_search(em, matches, reg)) {
        cout << matches.str() << endl;
        em = matches.str();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;
    //cout << "" << endl;
    //cin >> name;
    //cout << proverka(name);
    string email = "blablablabla p2yxjhnf@trashlify.com blablabla pubyvohuqu43@mail.ru vivovivovivo lymedydyga31@gmail.com";
    regex reg("[а-яa-zA-Z0-9_.]+@[а-яa-zA-Z0-9_]+\.[а-яa-zA-Z0-9]{2,}");
    smatch matches;
    while (regex_search(email, matches, reg)) {
        cout << matches.str() << endl;
        email = matches.suffix().str();
    }
}

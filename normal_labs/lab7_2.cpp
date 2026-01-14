#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string name;
    cout << "Введите своё имя: ";
    getline(cin, name);

    regex nameRegex("^[A-Z][a-zA-Z]{1,31}$");

    if (regex_match(name, nameRegex)) {
        cout << "Имя корректное!" << endl;
    } else {
        cout << "Имя некорректное!" << endl;
    }

    string text = "dsgfdfsidufnn test@gmail.com oodook,f ka@jegg.org. ""iisimmmsiw ad@mail.ru";

    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    auto begin = sregex_iterator(text.begin(), text.end(), emailRegex);
    auto end = sregex_iterator();

    cout << "\nНайденные e-mail адреса:\n";
    for (auto i = begin; i != end; ++i) {
        cout << i->str() << endl;
    }

    return 0;
}

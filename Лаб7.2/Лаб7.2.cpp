#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;
    cout << "Введите имя: ";
    cin >> name;

    regex namereg("^[A-Z][a-zA-Z]{1,31}$");

    if (regex_match(name, namereg))
    {
        cout << "Имя корректно\n";
    }
    else
    {
        cout << "Имя некорректно\n";
    }

    string text = "Напишите на rgrdhs@mail.ru или seerhg@gmail.com или lghnsag@yandex.ru ";

    regex emailReg("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");

    smatch matches;

    cout << "\nНайденные e-mail адреса:\n";

    while (regex_search(text, matches, emailReg))
    {
        cout << matches[0] << endl;
        text = matches.suffix().str();
    }

    return 0;
}

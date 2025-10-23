#include <iostream>
#include <regex>
#include "Windows.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name;
    cout << "Введите имя: ";
    cin >> name;
    regex reg("^[A-ZА-ЯЁ][a-zа-яё]{1,31}$");
    if (regex_match(name, reg)) {
        cout << "Имя корректно" << endl;
    }
    else { 
        cout << "Ошибка!\nДолжно быть:\nОт 2 до 32 символов." << endl;
        cout << "Содержать только буквы.\nПервая буква должна быть заглавной." << endl;
    }
    string text = "Пишите на email1@test.com или Sample@mail.ru, а также на backup@mail.net Русский email: Аыаыаыа@авыаыв.ру или";
    regex email_mask("[а-яa-zA-Z0-9_.]+@[а-яa-zA-Z0-9_]+.[а-яa-zA-Z0-9]{2,}");

    cout << "Найденные email-адреса:" << endl;

    smatch match;
    while (regex_search(text, match, email_mask)) {
        cout << match.str() << endl;
        text = match.suffix().str();
    }
}
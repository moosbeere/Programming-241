#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    // 1. Просим ввести имя
    cout << "Введите своё имя: ";
    string name;
    getline(cin, name);

    // 2. Регулярное выражение для проверки имени
    regex nameRegex("^[A-ZА-ЯЁ][a-zа-яё]{1,31}$", regex_constants::icase | regex_constants::ECMAScript);
    // Но надо вручную убедиться, что первая буква — заглавная
    bool valid = false;
    if (regex_match(name, nameRegex)) {
        if ((name[0] >= 'A' && name[0] <= 'Z') || (name[0] >= 'А' && name[0] <= 'Я') || name[0]=='Ё') {
            valid = true;
        }
    }
    if (valid) {
        cout << "Имя корректно." << endl;
    } else {
        cout << "Некорректное имя." << endl;
    }

    // 3. Произвольный текст с несколькими e-mail
    string text = "Пример: alex@example.com, olga.petrovna@gmail.com и info@university.edu находятся тут. А ещё: test123@site.ru.";

    // 4. Регэксп для email и вывод
    regex emailRegex(R"([\w\.-]+@[\w\.-]+\.\w+)");
    auto words_begin = sregex_iterator(text.begin(), text.end(), emailRegex);
    auto words_end = sregex_iterator();

    cout << "E-mail адреса в тексте:" << endl;
    for (auto it = words_begin; it != words_end; ++it) {
        cout << it->str() << endl;
    }
    return 0;
}

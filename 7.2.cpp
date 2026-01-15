#include <iostream> // Библиотека ввода-вывода
#include <string>   // Библиотека для работы со строками
#include <regex>    // Библиотека для работы с регулярными выражениями
using namespace std; // Использование стандартного пространства имен

int main() {
    setlocale(LC_ALL, "Russian"); // Поддержка русского языка в консоли

    // 1. Ввод имени
    cout << "Введите своё имя: ";
    string name;
    getline(cin, name); // Чтение строки целиком

    // 2. Регулярное выражение для проверки имени (от 2 до 32 символов)
    // ^ - начало, $ - конец, [a-z] - буквы. icase игнорирует регистр в шаблоне
    regex nameRegex("^[A-ZА-ЯЁ][a-zа-яё]{1,31}$", regex_constants::icase | regex_constants::ECMAScript);

    bool valid = false; // Флаг валидности
    if (regex_match(name, nameRegex)) { // Если строка соответствует шаблону
        // Проверяем вручную, что первый символ — заглавный (латиница или кириллица)
        if ((name[0] >= 'A' && name[0] <= 'Z') || (name[0] >= 'А' && name[0] <= 'Я') || name[0] == 'Ё') {
            valid = true;
        }
    }

    if (valid) {
        cout << "Имя корректно." << endl;
    }
    else {
        cout << "Некорректное имя (должно начинаться с большой буквы и быть без пробелов)." << endl;
    }

    // 3. Текст, в котором будем искать адреса почты
    string text = "Пример: alex@example.com, olga.petrovna@gmail.com и info@university.edu находятся тут. А ещё: test123@site.ru.";

    // 4. Регулярное выражение для поиска email
    // R"(...)" - сырая строка, чтобы не экранировать обратные слеши
    regex emailRegex(R"([\w\.-]+@[\w\.-]+\.\w+)");

    // Создание итераторов для поиска всех совпадений в тексте
    auto words_begin = sregex_iterator(text.begin(), text.end(), emailRegex);
    auto words_end = sregex_iterator(); // Пустой итератор (конец поиска)

    cout << "E-mail адреса в тексте:" << endl;
    // Цикл по всем найденным совпадениям
    for (auto it = words_begin; it != words_end; ++it) {
        cout << it->str() << endl; // Вывод найденной подстроки
    }

    return 0; // Завершение программы
}
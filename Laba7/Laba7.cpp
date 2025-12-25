#include <iostream>
#include <regex>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Settings {
public:
    static map<string, string> data;

    static void Add(const string& key, const string& value) {
        data[key] = value;
    }

    static string Get(const string& key) {
        auto it = data.find(key);
        if (it != data.end())
            return it->second;
        return "Ключ не найден";
    }

    static void Print() {
        if (data.empty()) {
            cout << "Настройки пусты\n";
            return;
        }
        cout << "Настройки\n";
        for (auto& k_v : data) {
            cout << k_v.first << " : " << k_v.second << "\n";
        }
        cout << "\n";
    }
};

map<string, string> Settings::data;

void p_vec(const vector<float>& vec) {
    cout << "Вектор: [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << " ";
    }
    cout << "]\n";
}

int main()
{
    setlocale(LC_ALL, "RUS");

    // Задание 1
    cout << "Введите строку: ";
    string str;
    getline(cin, str);

    // Задание 2 - подстрока
    if (str.length() >= 4) {
        string b = str.substr(1, 3);
        cout << "Подстрока (2-4 символы): " << b << "\n";
    }
    else {
        cout << "Строка слишком короткая для подстроки\n";
    }

    // Задание 3 - поиск 'a'
    size_t pos = str.find('a');
    if (pos != string::npos) {
        cout << "Индекс первого вхождения 'a': " << pos << "\n";
    }
    else {
        cout << "Символа a не найдено\n";
    }

    // Задание 4 - имя
    cout << "Введите ваше имя: ";
    string name;
    getline(cin, name);

    // Регулярное выражение для имени
    regex name_regex("^[A-ZА-ЯЁ][a-zа-яё]{1,31}$");

    if (regex_match(name, name_regex)) {
        cout << "Имя корректное\n";
    }
    else {
        cout << "Имя некорректное\n";
    }

    // Задание 5 - email в тексте
    string text = "sdfsdf ooo@example.com,sdfsdfsdf politech@yandex.mgu "
        "sdfsdfsd qwerty@mail.ru sdfsdf test.user+tag@example.co.uk";

    cout << "\nНайденные email:\n";

    regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    sregex_iterator begin(text.begin(), text.end(), email_regex);
    sregex_iterator end;

    for (sregex_iterator it = begin; it != end; ++it) {
        cout << "  " << it->str() << "\n";
    }

    // Задание 6 - длина окружности
    cout << "\nВведите радиус окружности: ";
    float r;
    cin >> r;
    cin.ignore();

    const float PI = 3.141592653589793f;
    float S = 2 * PI * r;
    cout << "Длина окружности: " << S << "\n";
    cout << fixed << setprecision(3);
    cout << "Длина окружности (округлено): " << S << "\n";

    cout.unsetf(ios::fixed);
    cout << setprecision(6); 

   
    cout << "Команды: read - показать содержимое, erase - очистить, exit - выход\n";

    const string filename = "text.txt";

    ofstream test_file(filename, ios::app);
    test_file.close();

    while (true) {
        cout << "\n> ";
        string input;
        getline(cin, input); 

        if (input == "read") {
            ifstream fin(filename);
            if (fin.is_open()) {
                cout << "\n Содержимое файла\n";
                string line;
                bool isEmpty = true;
                while (getline(fin, line)) {
                    cout << line << "\n";
                    isEmpty = false;
                }
                if (isEmpty) {
                    cout << "(файл пуст)\n";
                }
                cout << "\n";
                fin.close();
            }
            else {
                cout << "Ошибка открытия файла\n";
            }
        }
        else if (input == "erase") {
            ofstream fout(filename, ios::trunc);
            fout.close();
            cout << "Файл очищен\n";
        }
        else if (input == "exit") {
            cout << "Выход из программы...\n";
            break;
        }
        else {
            ofstream fout(filename, ios::app);
            if (fout.is_open()) {
                fout << input << "\n";
                fout.close();
                cout << "Строка добавлена в файл\n";
            }
            else {
                cout << "Ошибка записи в файл\n";
            }
        }
    }

    // Работа с вектором
    vector<float> vec;

    // Добавляем 5 элементов
    vec.push_back(32.123123f);
    vec.push_back(12.2323f);
    vec.push_back(3.3323f);
    vec.push_back(4.445f);
    vec.push_back(5.664565f);

    p_vec(vec);

    // Вставляем элемент между 3 и 4 элементами
    vec.insert(vec.begin() + 3, 2332.3f);
    p_vec(vec);

    // Удаляем последний элемент
    vec.pop_back();
    p_vec(vec);

    // Работа с классом Settings

    Settings::Add("Вес", "50");
    Settings::Add("Рост", "180");
    Settings::Add("Язык", "Русский");

    Settings::Print();

    cout << "Значение 'Вес': " << Settings::Get("Вес") << "\n";
    cout << "Значение 'Несуществующий': " << Settings::Get("Несуществующий") << "\n";

    return 0;
}
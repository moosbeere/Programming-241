#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// Функция для вывода содержимого вектора
void printVector(const vector<float>& v)
{
    cout << "Вектор: ";
    for (float x : v)
        cout << x << " ";
    cout << endl;
}

// Класс настроек
class Settings
{
public:
    // 14. Статическое поле Map
    static map<string, string> values;

    // 10. Добавление пары ключ-значение
    static void Add(const string& key, const string& value)
    {
        values[key] = value;
    }

    // 11. Получение значения по ключу
    static string Get(const string& key)
    {
        auto it = values.find(key);
        if (it != values.end())
            return it->second;
        return "";
    }

    // 12. Печать содержимого Map
    static void Print()
    {
        cout << "Settings:" << endl;
        for (const auto& [key, value] : values)
            cout << key << " = " << value << endl;
    }
};

// Определение статического поля
map<string, string> Settings::values {};

int main()
{
    // ===== 1-й блок: работа со строкой и подстрокой =====
    {
        string s;
        cout << "Введите строку: ";
        getline(cin, s);

        // 2. Подстрока со 2-го по 4-й символ (индексы 1..3)
        if (s.size() >= 4)
        {
            string sub = s.substr(1, 3);
            cout << "Подстрока со 2-го по 4-й символ: " << sub << endl;
        }
        else
        {
            cout << "Строка слишком короткая для подстроки 2..4" << endl;
        }

        // 3. Поиск первого 'a'
        size_t pos = s.find('a');
        if (pos == string::npos)
            cout << "Символа a не найдено" << endl;
        else
            cout << "Первое вхождение 'a' по индексу: " << pos << endl;
    }

    // ===== 2-й блок: имя и e-mail через регулярные выражения =====
    {
        // 1. Ввод имени
        string name;
        cout << "\nВведите своё имя: ";
        getline(cin, name);

        // 2. Регулярное выражение: 2–32 буквы, первая заглавная
        // Разрешим как латиницу, так и кириллицу
        regex nameRegex("^[A-ZА-Я][A-Za-zА-Яа-я]{1,31}$");

        if (regex_match(name, nameRegex))
            cout << "Имя корректно." << endl;
        else
            cout << "Имя некорректно." << endl;

        // 3. Строка с несколькими e-mail
        string text = "Мои почты: test@example.com, user123@mail.ru и another.address+tag@gmail.com.";

        // 4. Регулярное выражение для e-mail
        regex emailRegex(R"(([A-Za-z0-9._%+\-]+)@([A-Za-z0-9.\-]+)\.([A-Za-z]{2,}))");

        cout << "Найденные e-mail адреса:" << endl;
        sregex_iterator it(text.begin(), text.end(), emailRegex);
        sregex_iterator end;
        for (; it != end; ++it)
            cout << "  " << it->str() << endl;
    }

    // ===== 3-й блок: окружность и работа с файлом =====
    {
        // 1. Ввод радиуса и вычисление длины окружности
        double r;
        cout << "\nВведите радиус окружности: ";
        cin >> r;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка остатка строки

        const double PI = 3.141592653589793;
        double length = 2.0 * PI * r;

        cout << "Длина окружности: " << length << endl;

        // 3. Округление до 3 знаков
        double rounded = std::round(length * 1000.0) / 1000.0;
        cout << "Длина окружности (округлено до 3 знаков): "
             << fixed << setprecision(3) << rounded << endl;

        // 4–8. Работа с текстовым файлом
        const string filename = "lab7_text.txt";
        string line;

        cout << "\nВведите строки (команды: read, erase, exit):" << endl;
        while (true)
        {
            cout << "> ";
            if (!getline(cin, line))
                break;

            if (line == "read")
            {
                ifstream fin(filename);
                if (!fin)
                {
                    cout << "(Файл пока пуст или не существует)" << endl;
                }
                else
                {
                    cout << "--- Содержимое файла ---" << endl;
                    string fileLine;
                    while (getline(fin, fileLine))
                        cout << fileLine << endl;
                    cout << "------------------------" << endl;
                }
            }
            else if (line == "erase")
            {
                ofstream fout(filename, ios::trunc);
                cout << "Файл очищен." << endl;
            }
            else if (line == "exit")
            {
                cout << "Выход из программы." << endl;
                break;
            }
            else
            {
                ofstream fout(filename, ios::app);
                fout << line << '\n';
            }
        }
    }

    // ===== 4-й блок: вектор и класс Settings =====
    {
        // 1. Пустой вектор
        vector<float> v;

        // 2. Добавляем 5 элементов
        v.push_back(1.1f);
        v.push_back(2.2f);
        v.push_back(3.3f);
        v.push_back(4.4f);
        v.push_back(5.5f);

        // 3–4. Вывод через функцию
        cout << "\nВектор после добавления 5 элементов:" << endl;
        printVector(v);

        // 5. Вставка элемента между 3-м и 4-м элементами (индексы 2 и 3)
        if (v.size() >= 3)
        {
            v.insert(v.begin() + 3, 9.9f);
        }

        // 6. Проверка
        cout << "Вектор после вставки элемента между 3 и 4:" << endl;
        printVector(v);

        // 7. Удаляем последний элемент
        if (!v.empty())
            v.pop_back();

        // 8. Проверка
        cout << "Вектор после удаления последнего элемента:" << endl;
        printVector(v);

        // 9–15. Класс Settings

        // Предыдущая (нестатическая) проверка — теперь закомментирована, т.к. поле стало статическим:
        // Settings s;
        // s.Add("volume", "80");
        // s.Add("brightness", "50");
        // cout << "volume = " << s.Get("volume") << endl;
        // s.Print();

        // Теперь всё статическое:
        Settings::Add("volume", "80");
        Settings::Add("brightness", "50");
        Settings::Add("language", "ru");

        cout << "\nПроверка статического Settings:" << endl;
        cout << "volume = " << Settings::Get("volume") << endl;
        cout << "brightness = " << Settings::Get("brightness") << endl;
        Settings::Print();
    }

    return 0;
}


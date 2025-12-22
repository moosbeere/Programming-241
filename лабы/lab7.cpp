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
        auto it = values.find(key);  // auto - автоматическое определение типа (C++11)
                                      // find() - поиск элемента по ключу в map
                                      // возвращает итератор на найденный элемент или end()
        if (it != values.end())      // проверка, что элемент найден
                                      // values.end() - итератор "за последним" элементом
            return it->second;        // it->second - доступ к значению (value) пары ключ-значение
                                      // it->first - это ключ (key)
        return "";                     // если не найдено, возвращаем пустую строку
    }

    // 12. Печать содержимого Map
    static void Print()
    {
        cout << "Settings:" << endl;
        for (const auto& [key, value] : values)  // structured binding (C++17)
                                                 // автоматически разворачивает пару ключ-значение
                                                 // const auto& - константная ссылка, не копирует
                                                 // : values - range-based for по контейнеру
            cout << key << " = " << value << endl;
    }
};

// Определение статического поля
// статические поля класса должны быть определены вне класса
// Settings::values - полное имя с указанием класса через ::
// {} - инициализация пустым списком (пустая map)
map<string, string> Settings::values {};

int main()
{
    // ===== 1-й блок: работа со строкой и подстрокой =====
    {
        string s;
        cout << "Введите строку: ";
        getline(cin, s);

        // 2. Подстрока со 2-го по 4-й символ (индексы 1..3)
        if (s.size() >= 4)    // size() - метод, возвращающий длину строки
        {
            string sub = s.substr(1, 3);  // substr(позиция, длина) - извлечение подстроки
                                           // позиция 1 = второй символ (индексация с 0)
                                           // длина 3 = берём 3 символа (2-й, 3-й, 4-й)
            cout << "Подстрока со 2-го по 4-й символ: " << sub << endl;
        }
        else
        {
            cout << "Строка слишком короткая для подстроки 2..4" << endl;
        }

        // 3. Поиск первого 'a'
        size_t pos = s.find('a');  // find() - поиск символа в строке, возвращает позицию
                                    // size_t - беззнаковый целый тип для размеров и индексов
        if (pos == string::npos)   // npos - константа "не найдено" (максимальное значение size_t)
                                    // если символ не найден, find() возвращает npos
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
        // ^ - начало строки
        // [A-ZА-Я] - один символ: заглавная латинская или кириллическая буква
        // [A-Za-zА-Яа-я]{1,31} - от 1 до 31 символа: любые буквы (заглавные и строчные)
        // $ - конец строки
        regex nameRegex("^[A-ZА-Я][A-Za-zА-Яа-я]{1,31}$");
                              // regex - класс для работы с регулярными выражениями (C++11)

        if (regex_match(name, nameRegex))  // regex_match - проверка полного совпадения строки с шаблоном
                                           // возвращает true, если вся строка соответствует регулярному выражению
            cout << "Имя корректно." << endl;
        else
            cout << "Имя некорректно." << endl;

        // 3. Строка с несколькими e-mail
        string text = "Мои почты: test@example.com, user123@mail.ru и another.address+tag@gmail.com.";

        // 4. Регулярное выражение для e-mail
        // R"(...)" - raw string literal (C++11), позволяет не экранировать специальные символы
        // ([A-Za-z0-9._%+\-]+) - группа 1: имя пользователя (один или более символов)
        // @ - символ @
        // ([A-Za-z0-9.\-]+) - группа 2: доменное имя
        // \. - точка (экранированная)
        // ([A-Za-z]{2,}) - группа 3: доменная зона (2 или более буквы)
        regex emailRegex(R"(([A-Za-z0-9._%+\-]+)@([A-Za-z0-9.\-]+)\.([A-Za-z]{2,}))");

        cout << "Найденные e-mail адреса:" << endl;
        sregex_iterator it(text.begin(), text.end(), emailRegex);
                              // sregex_iterator - итератор для поиска всех совпадений в строке
                              // text.begin(), text.end() - диапазон для поиска (вся строка)
                              // создаёт итератор, указывающий на первое совпадение
        sregex_iterator end;  // итератор-конец (по умолчанию указывает на "за последним")
        for (; it != end; ++it)  // цикл по всем совпадениям
                                 // it != end - проверка, есть ли ещё совпадения
                                 // ++it - переход к следующему совпадению
            cout << "  " << it->str() << endl;  // it->str() - получение найденной подстроки
                                                // -> - доступ к методу через итератор
    }

    // ===== 3-й блок: окружность и работа с файлом =====
    {
        // 1. Ввод радиуса и вычисление длины окружности
        double r;
        cout << "\nВведите радиус окружности: ";
        cin >> r;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                              // ignore() - игнорирует символы из потока ввода
                              // numeric_limits<streamsize>::max() - максимальное количество символов
                              // '\n' - игнорировать до символа новой строки включительно
                              // необходимо после cin >> для очистки буфера перед getline()

        const double PI = 3.141592653589793;
        double length = 2.0 * PI * r;

        cout << "Длина окружности: " << length << endl;

        // 3. Округление до 3 знаков
        double rounded = std::round(length * 1000.0) / 1000.0;
                              // round() - округление до ближайшего целого
                              // * 1000.0 - сдвигаем запятую на 3 знака вправо
                              // / 1000.0 - сдвигаем обратно (получаем 3 знака после запятой)
        cout << "Длина окружности (округлено до 3 знаков): "
             << fixed << setprecision(3) << rounded << endl;
                              // fixed - формат с фиксированной точкой (не экспоненциальный)
                              // setprecision(3) - устанавливает 3 знака после запятой
                              // манипуляторы потока изменяют формат вывода

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
                ifstream fin(filename);  // ifstream - класс для чтения из файла
                                         // открывает файл для чтения
                if (!fin)                 // проверка успешности открытия файла
                                          // !fin - перегруженный оператор, возвращает true при ошибке
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
                              // ofstream - класс для записи в файл
                              // ios::trunc - режим открытия: обрезать файл до нулевой длины
                              // если файл существует, его содержимое удаляется
                cout << "Файл очищен." << endl;
            }
            else if (line == "exit")
            {
                cout << "Выход из программы." << endl;
                break;
            }
            else
            {
                ofstream fout(filename, ios::app);  // ios::app - режим добавления в конец файла
                                                     // append mode - данные добавляются, не перезаписывают
                fout << line << '\n';                // запись строки в файл
                                                      // << - оператор записи в поток
                                                      // '\n' - символ новой строки
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
        if (v.size() >= 3)  // проверка, что в векторе достаточно элементов
        {
            v.insert(v.begin() + 3, 9.9f);
                              // insert() - вставка элемента в вектор
                              // v.begin() - итератор на начало вектора
                              // v.begin() + 3 - итератор на 4-й элемент (индекс 3)
                              // 9.9f - значение для вставки (f означает float)
                              // элемент вставляется ПЕРЕД указанной позицией
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


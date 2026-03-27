#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

// 1. Создайте пустой вектор с типом float.
vector<float> numbers;

// 2. Добавьте 5 элементов в вектор.
numbers.push_back(1.1f);
numbers.push_back(2.2f);
numbers.push_back(3.3f);
numbers.push_back(4.4f);
numbers.push_back(5.5f);

// 3. Создайте функцию, которая принимает вектор и выводит его в консоли.
void PrintVector(const vector<float>& v) {
    cout << "Vector: ";
    for (float n : v) {
        cout << fixed << setprecision(2) << n << " ";
    }
    cout << endl;
}

// 4. Вызовите созданную функцию.
PrintVector(numbers);

// 5. Вставьте ещё один элемент между 3 и 4 элементами (индексы у них 2 и 3 соответственно).
numbers.insert(numbers.begin() + 3, 9.9f);

// 6. Проверьте правильность сделанного, выведя вектор в консоль.
PrintVector(numbers);

// 7. Удалите последний элемент.
numbers.pop_back();

// 8. Проверьте правильность сделанного, выведя вектор в консоль.
PrintVector(numbers);

// 9. Создайте класс Settings (настройки) и добавьте в него поле типа Map.
// 10. Добавьте в класс функцию Add, принимающую 2 строки (ключ и значение) и добавляющая их как новую пару в Map.
// 11. Добавьте в класс функцию Get, принимающую строку (ключ) и возвращающая соответствующее ей значение в Map.
// 12. Добавьте в класс функцию Print, которая будет выводить в консоль содержимое Map.

class Settings {
    // После 14-го задания это поле и методы будут статическими.
public:
    // 9. поле map
    map<string, string> settingsMap;

    // 10. Add
    void Add(const string& key, const string& value) {
        settingsMap[key] = value;
    }

    // 11. Get
    string Get(const string& key) const {
        auto it = settingsMap.find(key);
        if (it != settingsMap.end())
            return it->second;
        else
            return "";
    }

    // 12. Print
    void Print() const {
        cout << "Settings contents:" << endl;
        for (const auto& p : settingsMap) {
            cout << p.first << ": " << p.second << endl;
        }
    }
};

// 13. Создайте экземпляр класса Settings и проверьте работу всех созданных методов.
/*
Settings settings;
settings.Add("volume", "80");
settings.Add("theme", "dark");
cout << "Getting 'volume': " << settings.Get("volume") << endl;
cout << "Getting 'theme': " << settings.Get("theme") << endl;
cout << "Getting 'nonexistent': " << settings.Get("nonexistent") << endl;
settings.Print();
*/

// 14. Сделайте поле Map у класса Settings статическим, а также сделайте статическими все его функции.

class SettingsStatic {
public:
    static map<string, string> settingsMap;
    static void Add(const string& key, const string& value) {
        settingsMap[key] = value;
    }
    static string Get(const string& key) {
        auto it = settingsMap.find(key);
        if (it != settingsMap.end())
            return it->second;
        else
            return "";
    }
    static void Print() {
        cout << "SettingsStatic contents:" << endl;
        for (const auto& p : settingsMap) {
            cout << p.first << ": " << p.second << endl;
        }
    }
};

// Не забудьте определить статическую переменную
map<string, string> SettingsStatic::settingsMap;

// 15. Проверьте работу класса теперь, когда свойства и методы стали статическими.
SettingsStatic::Add("language", "ru");
SettingsStatic::Add("brightness", "70");
cout << "Brightness: " << SettingsStatic::Get("brightness") << endl;
cout << "Language: " << SettingsStatic::Get("language") << endl;
cout << "Nonexistent: " << SettingsStatic::Get("nonexistent") << endl;
SettingsStatic::Print();


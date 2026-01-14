#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;



void printVector(const vector<float>& vec) {
    for (float x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

// обычный класс с map ---------------------------------------------------------
class Settings {
private:
    map<string, string> m;
public:
    void Add(const string& key, const string& value) {
        m[key] = value;
    }
    string Get(const string& key) {
        if (m.find(key) != m.end()) return m[key];
        return "";
    }
    void Print() {
        for (auto& pair : m) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
};

// Статический класс Settings ---------------------------------------------------------
class SettingsStatic {
private:
    static map<string, string> m;
public:
    static void Add(const string& key, const string& value) {
        m[key] = value;
    }
    static string Get(const string& key) {
        if (m.find(key) != m.end()) return m[key];
        return "";
    }
    static void Print() {
        for (auto& pair : m) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
};

// Определение статического поля
map<string, string> SettingsStatic::m;


int main() {
    setlocale(LC_ALL, "RU");
    vector<float> numbers;

    numbers.push_back(1.1);
    numbers.push_back(2.2);
    numbers.push_back(3.3);
    numbers.push_back(4.4);
    numbers.push_back(5.5);

    cout << "Вектор после добавления 5 элементов: ";
    printVector(numbers);

    numbers.insert(numbers.begin() + 3, 99.9);

    cout << "Вектор после вставки 99.9 между 3 и 4 элементами: ";
    printVector(numbers);

    numbers.pop_back();

    cout << "Вектор после удаления последнего элемента: ";
    printVector(numbers);


    // тестирование
    Settings s;
    s.Add("volume", "50");
    s.Add("brightness", "80");
    s.Add("language", "English");

    cout << "Текущие настройки:\n";
    s.Print();

    cout << "Значение 'volume': " << s.Get("volume") << endl;

    // Тестирование статики
    SettingsStatic::Add("volume", "60");
    SettingsStatic::Add("brightness", "90");
    SettingsStatic::Add("language", "French");

    cout << "Текущие статические настройки:\n";
    SettingsStatic::Print();

    cout << "Значение 'language': " << SettingsStatic::Get("language") << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

// 3. Функция вывода вектора (должна быть объявлена до вызова)
void PrintVector(const vector<float>& v) {
    cout << "Vector: ";
    for (float n : v) {
        cout << fixed << setprecision(2) << n << " ";
    }
    cout << endl;
}

// 9-12. Класс Settings (обычный)
class Settings {
public:
    map<string, string> settingsMap;

    void Add(const string& key, const string& value) {
        settingsMap[key] = value;
    }

    string Get(const string& key) const {
        auto it = settingsMap.find(key);
        if (it != settingsMap.end())
            return it->second;
        return "";
    }

    void Print() const {
        cout << "Settings contents:" << endl;
        for (const auto& p : settingsMap) {
            cout << p.first << ": " << p.second << endl;
        }
    }
};

// 14. Класс SettingsStatic (статический)
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
        return "";
    }

    static void Print() {
        cout << "SettingsStatic contents:" << endl;
        for (const auto& p : settingsMap) {
            cout << p.first << ": " << p.second << endl;
        }
    }
};

// Определение статической переменной (обязательно вне класса)
map<string, string> SettingsStatic::settingsMap;

int main() {
    // Настройка русского языка
    setlocale(LC_ALL, "Russian");

    // --- РАБОТА С ВЕКТОРОМ ---

    // 1. Создаём вектор
    vector<float> numbers;

    // 2. Добавляем 5 элементов
    numbers.push_back(1.1f);
    numbers.push_back(2.2f);
    numbers.push_back(3.3f);
    numbers.push_back(4.4f);
    numbers.push_back(5.5f);

    // 4. Вызываем функцию вывода
    PrintVector(numbers);

    // 5. Вставляем элемент 9.9 между 3 и 4 элементами (индекс 3)
    numbers.insert(numbers.begin() + 3, 9.9f);

    // 6. Проверяем
    PrintVector(numbers);

    // 7. Удаляем последний
    numbers.pop_back();

    // 8. Проверяем
    PrintVector(numbers);

    cout << endl;

    // --- РАБОТА С КЛАССОМ SETTINGS ---

    // 13. Экземпляр обычного класса
    Settings settings;
    settings.Add("volume", "80");
    settings.Add("theme", "dark");
    cout << "Getting 'volume': " << settings.Get("volume") << endl;
    settings.Print();

    cout << endl;

    // --- РАБОТА СО СТАТИЧЕСКИМ КЛАССОМ ---

    // 15. Проверка статических методов (экземпляр не нужен)
    SettingsStatic::Add("language", "ru");
    SettingsStatic::Add("brightness", "70");
    cout << "Brightness: " << SettingsStatic::Get("brightness") << endl;
    SettingsStatic::Print();

    system("pause");
    return 0;
}
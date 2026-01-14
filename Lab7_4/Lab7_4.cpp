#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <locale>
#include <iomanip>

// 3. Функция для вывода вектора
void PrintVector(const std::vector<float>& vec) {
    std::wcout << L"Вектор: ";
    for (float val : vec) {
        std::wcout << val << L" ";
    }
    std::wcout << std::endl;
}

// 9-14. Класс Settings с русской поддержкой
class Settings {
public:
    // 14. Статическое поле Map
    static std::map<std::wstring, std::wstring> Map;

    // 14. Статическая функция Add
    static void Add(const std::wstring& key, const std::wstring& value) {
        Map[key] = value;
    }

    // 14. Статическая функция Get
    static std::wstring Get(const std::wstring& key) {
        if (Map.find(key) != Map.end())
            return Map[key];
        else
            return L"Ключ не найден";
    }

    // 14. Статическая функция Print
    static void Print() {
        std::wcout << L"Содержимое Map:" << std::endl;
        for (const auto& pair : Map) {
            std::wcout << pair.first << L" : " << pair.second << std::endl;
        }
    }
};

// Инициализация статического поля
std::map<std::wstring, std::wstring> Settings::Map;

int main() {
    // Устанавливаем русскую локаль для консоли
    setlocale(LC_ALL, "Russian");

    // 1. Создаем пустой вектор float
    std::vector<float> myVector;

    // 2. Добавляем 5 элементов
    myVector.push_back(1.1f);
    myVector.push_back(2.2f);
    myVector.push_back(3.3f);
    myVector.push_back(4.4f);
    myVector.push_back(5.5f);

    // 4. Вызов функции для вывода
    PrintVector(myVector);

    // 5. Вставляем элемент между 3 и 4 (индексы 2 и 3)
    myVector.insert(myVector.begin() + 3, 99.9f);

    // 6. Проверка вставки
    PrintVector(myVector);

    // 7. Удаляем последний элемент
    myVector.pop_back();

    // 8. Проверка удаления
    PrintVector(myVector);

    // 13. Проверка работы класса Settings
    std::wcout << L"\nРабота класса Settings (статические методы и поле):" << std::endl;
    Settings::Add(L"громкость", L"75");
    Settings::Add(L"яркость", L"50");
    Settings::Add(L"язык", L"Русский");

    std::wcout << L"Значение ключа 'громкость': " << Settings::Get(L"громкость") << std::endl;

    Settings::Print();

    // Комментарий: если бы Map и методы не были статическими, проверка выглядела бы так:
    /*
    Settings mySettings;
    mySettings.Add(L"громкость", L"75");
    mySettings.Add(L"яркость", L"50");
    mySettings.Add(L"язык", L"Русский");
    std::wcout << L"Значение ключа 'громкость': " << mySettings.Get(L"громкость") << std::endl;
    mySettings.Print();
    */

    return 0;
}

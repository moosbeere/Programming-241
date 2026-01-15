#define _USE_MATH_DEFINES   // включаем математические константы
#include <iostream>
#include <array>
#include <fstream>
#include <map>
#include <vector>
#include <regex>
#include <algorithm>
#include <cmath>

// Задание 1
static void task_1()
{
    std::string user_data;
    std::cin >> user_data;

    // Берем подстроку, если длина позволяет
    if (user_data.size() >= 4)
        std::cout << "Подстрока: " << user_data.substr(1, 3) << std::endl;

    // Поиск первого символа 'a'
    const size_t index = user_data.find('a');
    if (index != std::string::npos)
        std::cout << "Индекс 'a': " << index << std::endl;
    else
        std::cout << "Символ 'a' не найден" << std::endl;
}

// Проверка имени пользователя
static bool user_name_validation(const std::string& name)
{
    // Длина имени
    if (name.size() < 2 || name.size() > 32)
        return false;

    // Первая буква должна быть заглавной
    if (!std::isupper(static_cast<unsigned char>(name[0])))
        return false;

    // Все символы — только буквы
    for (const char ch : name)
    {
        if (!std::isalpha(static_cast<unsigned char>(ch)))
            return false;
    }

    return true;
}

// Задание 2
static void task_2()
{
    std::string name;
    std::cin >> name;

    // Regex для имени (заглавная буква + 31 латинская буква
    const std::regex name_regex("^[A-Z][a-zA-Z]{1,31}$");

    if (std::regex_match(name, name_regex))
        std::cout << "Имя пользователя корректно" << std::endl;
    else
        std::cout << "Имя пользователя некорректно" << std::endl;

    // Regex для email
    const std::regex email_regex(R"([a-zA-Z0-9._%+-]+@([a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");

    std::string emails =
        "vasya_kopaev@mail.com \n"
        "hello@custom-domain.com \n"
        "aslkejf \n";

    std::smatch matches;

    // Поиск всех email в строке
    while (std::regex_search(emails, matches, email_regex)) {
        std::cout << matches[0] << std::endl;
        emails = matches.suffix();
    }
}

// Задание 3
static void task_3()
{
    int radius = 0;
    std::cin >> radius;

    const double length = 2.0 * M_PI * radius;

    std::cout << "Длина окружности: " << static_cast<int>(length) << std::endl;
    std::cout << "Округление: " << std::round(length * 1000) / 1000 << std::endl;

    std::ofstream file("text.txt", std::ios::trunc);
    std::string buffer;

    while (true)
    {
        std::string command;
        std::cin >> command;

        if (command == "read")
        {
            std::cout << buffer << std::endl;
        }
        else if (command == "erase")
        {
            buffer.clear();
            std::cout << "Файл очищен" << std::endl;
        }
        else if (command == "exit")
        {
            file << buffer;
            break;
        }
        else
        {
            buffer += command;
        }
    }
}

// Функция печати вектора
static void print_vector(const std::vector<float>& values)
{
    for (float value : values)
        std::cout << value << std::endl;

    std::cout << "----------------" << std::endl;
}

// Класс глобальных настроек
class Settings
{
public:
    // Добавление значения по ключу
    static void add(const std::string& key, const std::string& value)
    {
        m_values.emplace(key, value);
    }

    // Получение значения (без создания нового)
    static const std::string& get(const std::string& key)
    {
        return m_values.at(key);
    }

    // Печать всех настроек
    static void print()
    {
        for (const auto& [key, value] : m_values)
            std::cout << "Key: " << key << " Value: " << value << std::endl;
    }

private:
    // Статичное поле класса
    static inline std::map<std::string, std::string> m_values;
};

// Задание 4
static void task_4()
{
    std::vector<float> values{ 12.9f, 5.9f, 4.9242f, 8.1355f, 1.1f };
    print_vector(values);

    values.insert(values.begin() + 3, 1.12f);
    print_vector(values);

    values.pop_back();
    print_vector(values);

    Settings::add("key_1", "12");
    Settings::add("key_2", "24");
    Settings::add("pepe", "frfrfrr");
    Settings::print();
}


int main()
{
    std::setlocale(LC_ALL, "Russian");

    task_3();
}

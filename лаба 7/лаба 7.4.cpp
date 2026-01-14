#include <iostream>
#include <vector>
#include <map>
#include <string>

// 1-8. Работа с вектором
void vectorOperations() {
    std::cout << "=== Работа с вектором ===" << std::endl;
    
    // 1. Создание пустого вектора с типом float
    std::vector<float> floatVector;
    
    // 2. Добавление 5 элементов в вектор
    std::cout << "Добавляем 5 элементов: ";
    for (int i = 0; i < 5; ++i) {
        float value = i * 1.5f;
        floatVector.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    // 3. Функция для вывода вектора
    auto printVector = [](const std::vector<float>& vec) {
        std::cout << "Вектор: [";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    };
    
    // 4. Вызов функции вывода
    printVector(floatVector);
    
    // 5. Вставка элемента между 3 и 4 элементами (индексы 2 и 3)
    floatVector.insert(floatVector.begin() + 3, 99.9f);
    
    // 6. Проверка правильности вставки
    std::cout << "После вставки 99.9 между 3 и 4 элементами:" << std::endl;
    printVector(floatVector);
    
    // 7. Удаление последнего элемента
    floatVector.pop_back();
    
    // 8. Проверка правильности удаления
    std::cout << "После удаления последнего элемента:" << std::endl;
    printVector(floatVector);
    
    std::cout << std::endl;
}

// 9-13. Класс Settings (нестатическая версия)
class Settings {
private:
    std::map<std::string, std::string> settingsMap;
    
public:
    // 10. Функция Add для добавления пары ключ-значение
    void Add(const std::string& key, const std::string& value) {
        settingsMap[key] = value;
        std::cout << "Добавлено: " << key << " = " << value << std::endl;
    }
    
    // 11. Функция Get для получения значения по ключу
    std::string Get(const std::string& key) {
        auto it = settingsMap.find(key);
        if (it != settingsMap.end()) {
            return it->second;
        }
        return "Ключ не найден";
    }
    
    // 12. Функция Print для вывода содержимого Map
    void Print() const {
        std::cout << "Настройки (Map):" << std::endl;
        if (settingsMap.empty()) {
            std::cout << "  Map пуст" << std::endl;
        } else {
            for (const auto& pair : settingsMap) {
                std::cout << "  " << pair.first << " = " << pair.second << std::endl;
            }
        }
    }
    
    // Дополнительно: функция для получения размера Map
    size_t Size() const {
        return settingsMap.size();
    }
};

// 14-15. Статическая версия класса Settings
class StaticSettings {
private:
    // 14. Статическое поле Map
    static std::map<std::string, std::string> settingsMap;
    
public:
    // 14. Статическая функция Add
    static void Add(const std::string& key, const std::string& value) {
        settingsMap[key] = value;
        std::cout << "Добавлено (статическое): " << key << " = " << value << std::endl;
    }
    
    // 14. Статическая функция Get
    static std::string Get(const std::string& key) {
        auto it = settingsMap.find(key);
        if (it != settingsMap.end()) {
            return it->second;
        }
        return "Ключ не найден";
    }
    
    // 14. Статическая функция Print
    static void Print() {
        std::cout << "Настройки (статический Map):" << std::endl;
        if (settingsMap.empty()) {
            std::cout << "  Map пуст" << std::endl;
        } else {
            for (const auto& pair : settingsMap) {
                std::cout << "  " << pair.first << " = " << pair.second << std::endl;
            }
        }
    }
    
    // Дополнительно: статическая функция для получения размера Map
    static size_t Size() {
        return settingsMap.size();
    }
    
    // Дополнительно: статическая функция для очистки Map
    static void Clear() {
        settingsMap.clear();
        std::cout << "Статический Map очищен" << std::endl;
    }
};

// Инициализация статического поля
std::map<std::string, std::string> StaticSettings::settingsMap;

int main() {
    // Установка локали для поддержки русского языка
    std::locale::global(std::locale(""));
    
    // Выполнение операций с вектором
    vectorOperations();
    
    // ==============================================
    // 9-13. Проверка нестатического класса Settings
    // ==============================================
    std::cout << "=== Проверка нестатического класса Settings ===" << std::endl;
    
    // 13. Создание экземпляра класса Settings
    Settings settings;
    
    // Проверка пустого Map
    settings.Print();
    
    // Добавление элементов
    settings.Add("language", "Russian");
    settings.Add("theme", "dark");
    settings.Add("fontSize", "14");
    settings.Add("autoSave", "true");
    
    // Вывод всех элементов
    settings.Print();
    
    // Получение значений по ключам
    std::cout << "Получение значений:" << std::endl;
    std::cout << "  language = " << settings.Get("language") << std::endl;
    std::cout << "  theme = " << settings.Get("theme") << std::endl;
    std::cout << "  несуществующий ключ = " << settings.Get("invalidKey") << std::endl;
    
    std::cout << std::endl;
    
    // ==============================================
    // 14-15. Проверка статического класса Settings
    // ==============================================
    /*
    std::cout << "=== Проверка статического класса Settings ===" << std::endl;
    
    // Сначала очистим статический Map (на всякий случай)
    StaticSettings::Clear();
    
    // Проверка пустого Map
    StaticSettings::Print();
    
    // Добавление элементов (без создания экземпляра класса)
    StaticSettings::Add("server", "localhost");
    StaticSettings::Add("port", "8080");
    StaticSettings::Add("timeout", "30");
    StaticSettings::Add("maxConnections", "100");
    
    // Вывод всех элементов
    StaticSettings::Print();
    
    // Получение значений по ключам
    std::cout << "Получение значений:" << std::endl;
    std::cout << "  server = " << StaticSettings::Get("server") << std::endl;
    std::cout << "  port = " << StaticSettings::Get("port") << std::endl;
    std::cout << "  несуществующий ключ = " << StaticSettings::Get("invalidKey") << std::endl;
    
    // Проверка, что все элементы доступны из разных мест программы
    
    // Создадим еще один "пользователь" статических настроек
    std::cout << "\nДругой пользователь статических настроек:" << std::endl;
    StaticSettings::Add("user", "admin");
    StaticSettings::Print();
    
    // Размер статического Map
    std::cout << "Размер статического Map: " << StaticSettings::Size() << std::endl;
    */
    
    return 0;
}
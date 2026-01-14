#include <iostream>
#include <string>
#include <windows.h>  // для Windows и SetConsoleCP

int main() {
    // Установка кодировки для русского языка в Windows консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // 1. Запрос строки у пользователя
    std::string userString;
    std::cout << "Введите строку: ";
    std::getline(std::cin, userString);
    
    // 2. Вывод подстроки от 2-го до 4-го символа включительно
    if (userString.length() >= 4) {
        std::string substring = userString.substr(1, 3);
        std::cout << "Подстрока от 2-го до 4-го символа: " << substring << std::endl;
    } else {
        std::cout << "Строка слишком короткая для получения подстроки" << std::endl;
    }
    
    // 3. Поиск индекса первого вхождения 'a'
    size_t index = userString.find('a');
    if (index != std::string::npos) {
        std::cout << "Индекс первого вхождения 'a': " << index << std::endl;
    } else {
        std::cout << "Символа a не найдено" << std::endl;
    }
    
    return 0;
}
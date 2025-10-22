#include <iostream> // Подключаем поток вывода в консоль
#include <string>

int main() { // Точка входа в программу
    
    std::cout << "First string" << std::endl; // 1) Вывод строки на английском
    std::cout << "«Первая строка»\n«Вторая строка»" << std::endl; // 2) Две строки через \n


    std::cout << "Спецсимволы \"\\\"" << std::endl; // 4) Экранированные кавычки и обратный слеш

    int integerValue = 150;
    float floatValue = 15.933;
    unsigned char minimalMemoryValue = 250;

    std::cout << "integerValue = " << integerValue << std::endl;
    std::cout << "floatValue = " << floatValue << std::endl;
    std::cout << "minimalMemoryValue=" << static_cast<int>(minimalMemoryValue) << std::endl;

    unsigned day = 19;             
    std::string month = "ноября"; 
    unsigned year = 2005;          

    std::cout << "Моя дата рождения: "
              << day << ' ' << month << ' ' << year << " года" << std::endl;

    const double twoPointThree = 2.3;
    const std::string WINDOWS = "WINDOWS";

    std::cout << twoPointThree << ' ' << WINDOWS << std::endl;

    return 0; // Возвращаем код успешного завершения
} // Конец функции main
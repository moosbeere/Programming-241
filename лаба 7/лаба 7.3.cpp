#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

int main() {
    // Установка локали для поддержки русского языка
    std::locale::global(std::locale(""));
    
    // 1. Запрос радиуса окружности
    double radius;
    std::cout << "Введите радиус окружности: ";
    std::cin >> radius;
    
    // 2. Вычисление и вывод длины окружности
    const double pi = 3.14159265358979323846;
    double circumference = 2 * pi * radius;
    std::cout << "Длина окружности: " << circumference << std::endl;
    
    // 3. Округление до 3-х знаков после запятой
    std::cout << "Длина окружности (округленная до 3 знаков): ";
    std::cout << std::fixed << std::setprecision(3) << circumference << std::endl;
    
    // Сбрасываем поток ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // 4-8. Работа с файлом в бесконечном цикле
    std::string filename = "data.txt";
    
    while (true) {
        std::cout << "\nВведите строку (read - прочитать файл, erase - очистить файл, exit - выход): ";
        std::string input;
        std::getline(std::cin, input);
        
        // 8. Если пользователь вводит "exit" - завершаем программу
        if (input == "exit") {
            std::cout << "Выход из программы." << std::endl;
            break;
        }
        
        // 6. Если пользователь вводит "read" - читаем содержимое файла
        else if (input == "read") {
            std::ifstream inFile(filename);
            if (inFile.is_open()) {
                std::cout << "\nСодержимое файла '" << filename << "':\n";
                std::string line;
                while (std::getline(inFile, line)) {
                    std::cout << line << std::endl;
                }
                inFile.close();
            } else {
                std::cout << "Файл не найден или не может быть открыт." << std::endl;
            }
        }
        
        // 7. Если пользователь вводит "erase" - очищаем файл
        else if (input == "erase") {
            std::ofstream outFile(filename, std::ios::trunc);
            if (outFile.is_open()) {
                outFile.close();
                std::cout << "Файл очищен." << std::endl;
            } else {
                std::cout << "Ошибка при открытии файла для очистки." << std::endl;
            }
        }
        
        // 5. В остальных случаях записываем строку в конец файла
        else {
            std::ofstream outFile(filename, std::ios::app);
            if (outFile.is_open()) {
                outFile << input << std::endl;
                outFile.close();
                std::cout << "Строка добавлена в файл." << std::endl;
            } else {
                std::cout << "Ошибка при открытии файла для записи." << std::endl;
            }
        }
    }
    
    return 0;
}
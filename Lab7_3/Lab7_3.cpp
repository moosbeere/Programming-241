#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>
#include <cmath>

int main() {
    // Устанавливаем русскую локаль для консоли
    setlocale(LC_ALL, "Russian");

    // 1. Запрос радиуса
    double radius;
    std::wcout << L"Введите радиус окружности: ";
    std::wcin >> radius;
    std::wcin.ignore(); // очищаем буфер

    // 2. Вычисление длины окружности
    const double PI = 3.14159265358979323846; // Определяем π вручную
    double circumference = 2 * PI * radius;
    std::wcout << L"Длина окружности: " << circumference << std::endl;

    // 3. Округление до 3 знаков после запятой
    std::wcout << L"Длина окружности (округлённая до 3 знаков): "
        << std::fixed << std::setprecision(3) << circumference << std::endl;

    // Имя файла
    std::wstring filename = L"textfile.txt";

    // 4-8. Бесконечный цикл для ввода строк
    while (true) {
        std::wstring input;
        std::wcout << L"Введите строку (read, erase, exit): ";
        std::getline(std::wcin, input);

        if (input == L"read") {
            // 6. Выводим содержимое файла
            std::wifstream infile(filename);
            infile.imbue(std::locale(".UTF8")); // читаем в UTF-8
            if (!infile) {
                std::wcout << L"Файл пуст или не существует." << std::endl;
            }
            else {
                std::wcout << L"Содержимое файла:" << std::endl;
                std::wstring line;
                while (std::getline(infile, line)) {
                    std::wcout << line << std::endl;
                }
            }
        }
        else if (input == L"erase") {
            // 7. Очистка файла
            std::wofstream outfile(filename, std::ios::trunc);
            outfile.imbue(std::locale(".UTF8"));
            std::wcout << L"Файл очищен." << std::endl;
        }
        else if (input == L"exit") {
            // 8. Выход из программы
            std::wcout << L"Программа завершена." << std::endl;
            break;
        }
        else {
            // 5. Запись строки в файл
            std::wofstream outfile(filename, std::ios::app);
            outfile.imbue(std::locale(".UTF8")); // записываем в UTF-8
            outfile << input << std::endl;
        }
    }

    return 0;
}

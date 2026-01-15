#include <iostream>  // Библиотека ввода-вывода (cout, cin)
#include <fstream>   // Библиотека для работы с файлами (ifstream, ofstream)
#include <string>    // Библиотека для работы со строками string
#include <cmath>     // Библиотека для математических функций
#include <iomanip>   // Библиотека для форматирования вывода (setprecision)
using namespace std; // Использование стандартного пространства имен

int main() {
    setlocale(LC_ALL, "Russian"); // Поддержка русского языка в консоли

    // 1. Ввод радиуса
    cout << "Введите радиус окружности: ";
    double r; // Переменная для радиуса
    cin >> r; // Чтение числа

    // 2. Вычисление длины окружности
    const double PI = 3.14159265358979323846; // Константа числа Пи
    double length = 2 * PI * r; // Формула длины окружности

    // 3. Округление и вывод
    cout << fixed << setprecision(3); // Установка 3 знаков после запятой
    cout << "Длина окружности: " << length << endl;

    // 4-8. Работа с файлом и пользовательским вводом
    cin.ignore(); // Очистка буфера после ввода числа (удаление символа Enter)
    const string filename = "circle_text.txt"; // Имя файла для записи

    while (true) { // Бесконечный цикл взаимодействия
        cout << "Введите строку (или read/erase/exit): ";
        string userInput;
        getline(cin, userInput); // Чтение строки с пробелами

        if (userInput == "read") { // Если команда на чтение
            ifstream inFile(filename); // Открытие файла для чтения
            if (inFile) { // Если файл успешно открыт
                string line;
                cout << "--- Содержимое файла ---" << endl;
                while (getline(inFile, line)) { // Построчное чтение до конца
                    cout << line << endl;
                }
                cout << "--- Конец файла ---" << endl;
            }
            else {
                cout << "(Файл пуст или не существует)" << endl;
            }
        }
        else if (userInput == "erase") { // Если команда на удаление
            ofstream ofs(filename, ios::trunc); // Открытие в режиме перезаписи (очистки)
            cout << "Файл очищен." << endl;
        }
        else if (userInput == "exit") { // Выход из программы
            cout << "Завершение программы." << endl;
            break; // Разрыв цикла
        }
        else { // Если введена любая другая строка
            ofstream outFile(filename, ios::app); // Открытие в режиме добавления (append)
            outFile << userInput << endl; // Запись строки в конец файла
        }
    }
    return 0; // Завершение программы
}
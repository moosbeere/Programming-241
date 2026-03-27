#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // 1. Ввод радиуса
    cout << "Введите радиус окружности: ";
    double r;
    cin >> r;

    // 2. Вычисление длины окружности
    const double PI = 3.14159265358979323846;
    double length = 2 * PI * r;

    // 3. Округление и вывод
    cout << fixed << setprecision(3);
    cout << "Длина окружности: " << length << endl;

    // 4-8. Работа с файлом и пользовательским вводом
    cin.ignore(); // Сбросить символ новой строки после cin >> r
    const string filename = "circle_text.txt";
    while (true) {
        cout << "Введите строку (или read/erase/exit): ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "read") {
            ifstream inFile(filename);
            if (inFile) {
                string line;
                cout << "--- Содержимое файла ---" << endl;
                while (getline(inFile, line)) {
                    cout << line << endl;
                }
                cout << "--- Конец файла ---" << endl;
            } else {
                cout << "(Файл пуст или не существует)" << endl;
            }
        } else if (userInput == "erase") {
            ofstream ofs(filename, ios::trunc);
            // файл очищен
            cout << "Файл очищен." << endl;
        } else if (userInput == "exit") {
            cout << "Завершение программы." << endl;
            break;
        } else {
            ofstream outFile(filename, ios::app);
            outFile << userInput << endl;
        }
    }
    return 0;
}

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    double r;
    cout << "Введите радиус окружности: ";
    cin >> r;
    cout << "Длина окружности (округлённая до 3 знаков) = " << trunc(2 * M_PI * r * 1000 + 0.5) / 1000 << endl;
    
    string s1;
    fstream fs;
    while (true) {
        cout << "Введите строку: ";
        cin >> s1;
        if (s1 == "read") {
            cout << "Содержимое файла: " << endl;
            fs.open("example.txt", ios::in);
            string line;
            while (getline(fs, line)) {
                cout << line << endl;
            }
            fs.close();
        }
        else if (s1 == "erase") {
            fs.open("example.txt", ios::out);
            cout << "Файл очищен." << endl;
            fs.close();
        }
        else if (s1 == "exit") {
            cout << "Завершение программы.";
            break;
        }
        else {
            fs.open("example.txt", ios::app);
            fs << s1 << endl;
            fs.close();
        }
    }
}
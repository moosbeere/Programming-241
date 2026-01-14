#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // для setprecision
#include <cmath>   // для M_PI

using namespace std;

int main() {
    double r;
    cout << "Введите радиус окружности: ";
    cin >> r;

    double length = 2 * M_PI * r;

    cout << fixed << setprecision(3);
    cout << "Длина окружности: " << length << endl;

    cin.ignore(); // чтобы убрать символ новой строки из буфера перед getline


    const string filename = "text.txt";
    while (true) {
        string input;
        cout << "Введите строку или команды read/erase/exit: ";
        getline(cin, input);

        if (input == "exit") {
            break;
        } 
        else if (input == "read") {
            ifstream fin(filename);
            if (!fin) {
                cout << "Файл не существует." << endl;
            } else {
                string line;
                cout << "\nСодержимое файла:\n";
                while (getline(fin, line)) {
                    cout << line << endl;
                }
                cout << endl;
            }
            fin.close();
        } 
        else if (input == "erase") {
            ofstream fout(filename, ios::trunc);
            fout.close();
            cout << "Файл очищен." << endl;
        } 
        else {
            ofstream fout(filename, ios::app);
            fout << input << endl;
            fout.close();
        }
    }

    cout << "Программа завершена." << endl;
    return 0;
}

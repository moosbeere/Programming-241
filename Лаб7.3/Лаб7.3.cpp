#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double r;
    cout << "Введите радиус окружности: ";
    cin >> r;
    const double PI = 3.141592653589793;
    double length = 2 * PI * r;

    double rounded = round(length * 1000) / 1000;

    cout << "Длина окружности: " << rounded << endl;

    cin.ignore();

    string input;
    fstream file;

    while (true)
    {
        cout << "\nВведите строку: ";
        getline(cin, input);

        if (input == "exit")
        {
            break;
        }

        if (input == "read")
        {
            file.open("text.txt", ios::in);
            string line;

            while (getline(file, line))
            {
                cout << line << endl;
            }

            file.close();
            continue;
        }

        if (input == "erase")
        {
            file.open("text.txt", ios::out | ios::trunc);
            file.close();
            cout << "Файл очищен\n";
            continue;
        }

        file.open("text.txt", ios::out | ios::app);
        file << input << endl;
        file.close();
    }

    return 0;
}

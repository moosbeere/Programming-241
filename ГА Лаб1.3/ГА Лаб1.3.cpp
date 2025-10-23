#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int const size = 5;

    string phones[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        int num3 = rand() % 100;
        phones[i] = to_string(num1) + "-" + to_string(num2) + "-" + to_string(num3);
    }

    cout << "Исходный список телефонов: " << endl;
    for (int i = 0; i < size; i++) {
        cout << phones[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (phones[j] < phones[min]) {
                min = j;
            }
        }
        string x = phones[i];
        phones[i] = phones[min];
        phones[min] = x;
    }

    cout << "Отсортированный список телефонов: " << endl;
    for (int i = 0; i < size; i++) {
        cout << phones[i] << endl;
    }
    return 0;
}
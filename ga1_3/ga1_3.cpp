#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 5;
    string phones[N] = {
        "23-45-67",
        "10-22-33",
        "99-11-00",
        "45-12-89",
        "01-02-03"
    };

    cout << "Исходный список телефонов:\n";
    for (int i = 0; i < N; i++)
        cout << phones[i] << endl;

    // Сортировка выбором по возрастанию
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (phones[j] < phones[minIndex])
                minIndex = j;
        }
        swap(phones[i], phones[minIndex]);
    }

    cout << "\nОтсортированный список телефонов:\n";
    for (int i = 0; i < N; i++)
        cout << phones[i] << endl;

    return 0;
}

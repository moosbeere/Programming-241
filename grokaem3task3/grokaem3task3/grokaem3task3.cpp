#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void бысорт(vector<int>& м, int л, int п) {
    if (л >= п) return;

    int оп = м[п];
    int i = л - 1;

    for (int j = л; j < п; j++) {
        if (м[j] <= оп) {
            i++;
            swap(м[i], м[j]);
        }
    }
    swap(м[i + 1], м[п]);
    int т = i + 1;

    бысорт(м, л, т - 1);
    бысорт(м, т + 1, п);
}

void сортироватьСтолбец(vector<vector<int>>& м) {
    int стр = м.size();
    if (стр == 0) return;

    vector<int> столбец(стр);
    for (int i = 0; i < стр; i++) {
        столбец[i] = м[i][0];
    }

    бысорт(столбец, 0, стр - 1);

    for (int i = 0; i < стр; i++) {
        м[i][0] = столбец[i];
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int С = 6;
    const int Т = 5;

    vector<vector<int>> м(С, vector<int>(Т));

    srand(time(0));

   
    cout << "Создание массива " << С << "×" << Т << " в диапазоне {5,61}..." << endl;
    for (int i = 0; i < С; i++) {
        for (int j = 0; j < Т; j++) {
            м[i][j] = 5 + rand() % 57;
        }
    }

    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < С; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < Т; j++) {
            cout << setw(3) << м[i][j] << " ";
        }
        cout << endl;
    }

    сортироватьСтолбец(м);

    cout << "\nПосле сортировки первого столбца:" << endl;
    for (int i = 0; i < С; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < Т; j++) {
            cout << setw(3) << м[i][j] << " ";
        }
        cout << endl;
    }

    bool кор = true;
    for (int i = 1; i < С; i++) {
        if (м[i][0] < м[i - 1][0]) {
            кор = false;
            break;
        }
    }

    cout << "\n" << (кор ? "✓ Первый столбец отсортирован!" : "✗ Ошибка сортировки!") << endl;

    return 0;
}
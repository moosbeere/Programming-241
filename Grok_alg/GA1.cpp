#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Сортировка выбором по возрастанию ----------
void vozrast(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ---------- Сортировка выбором по убыванию ----------
void ubiv(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

// ---------- Сортировка списка телефонов ----------
void selectionSortPhones(vector<string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (phones[j] < phones[minIndex]) {
                minIndex = j;
            }
        }
        swap(phones[i], phones[minIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));


    int N = 10;
    int arrV[N];
    for (int i = 0; i < N; i++) {
        arrV[i] = 2 + rand() % 102;
    }

    cout << "\nИсходный массив:\n";
    for (int x : arrV) cout << x << " ";
    cout << endl;

    vozrast(arrV, N);

    cout << "Отсортированный массив (возрастание):\n";
    for (int x : arrV) cout << x << " ";
    cout << endl;


    int arrU[N];
    for (int i = 0; i < N; i++) {
        arrU[i] = rand() % 101;
    }

    cout << "\nИсходный массив:\n";
    for (int x : arrU) cout << x << " ";
    cout << endl;

    ubiv(arrU, N);

    cout << "Отсортированный массив (убывание):\n";
    for (int x : arrU) cout << x << " ";
    cout << endl;



    vector<string> phones = {
        "23-45-67",
        "12-34-56",
        "89-01-23",
        "45-67-89",
        "01-23-45"
    };

    cout << "\nИсходный список телефонов:\n";
    for (auto &p : phones) cout << p << endl;

    selectionSortPhones(phones);

    cout << "\nОтсортированный список телефонов:\n";
    for (auto &p : phones) cout << p << endl;


    return 0;
}

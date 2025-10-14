#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool sravnenieTelefonov(const string& a, const string& b) {
    return a < b;
}

void sortirovkaViborom(vector<string>& a1) {
    int n = a1.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (sravnenieTelefonov(a1[j], a1[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a1[i], a1[minIndex]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<string> phones = {
        "23-45-67",
        "12-34-56",
        "89-01-23",
        "45-67-89",
        "34-56-78",
        "67-89-01"
    };
    cout << "Исходный список телефонов:" << "\n";
    int n = phones.size();
    for (int i = 0; i < n; i++) {
        cout << phones[i] << "\n";
    }
    sortirovkaViborom(phones);
    cout << "Отсортированный список телефонов:" << "\n";
    int n1 = phones.size();
    for (int i = 0; i < n1; i++) {
        cout << phones[i] << "\n";
    }
}

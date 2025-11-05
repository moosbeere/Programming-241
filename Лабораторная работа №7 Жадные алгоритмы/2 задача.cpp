#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите кол-во коробок: ";
    cin >> n;
    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; i++) {
        cout << "Введите собственный вес коробки и вес, который она сможет выдержать: ";
        cin >> boxes[i].first >> boxes[i].second;
    }
    sort(boxes.begin(), boxes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first + a.second) < (b.first + b.second);
        });
    long long current_weight = 0;
    int count = 0;
    for (const auto& box : boxes) {
        if (current_weight <= box.second) {
            count++;
            current_weight += box.first;
        }
    }
    cout << "Наибольшее кол-во коробок: " << count;
}
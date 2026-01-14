#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<pair<int, int>>& vec) {
    for (auto elem : vec) {
        cout << elem.first << " " << elem.second << endl;
    }
}

bool compWeight(pair<int, int>& a, pair<int, int>& b) {
    return a.first + a.second < b.first + b.second;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите количество коробок: ";
    cin >> n;
    vector<pair<int, int>> presents(n);
    for (int i = 0; i < n; i++) {
        cin >> presents[i].first >> presents[i].second;
    }
    sort(presents.begin(), presents.end(), compWeight);
    // printArr(presents);
    int total = 0;
    int count = 0;
    for (auto elem : presents) {
        if (total <= elem.second) {
            count++;
            total += elem.first;
        }
    }
    cout << "Количество сложенных друг на друга коробок: " << count;
}
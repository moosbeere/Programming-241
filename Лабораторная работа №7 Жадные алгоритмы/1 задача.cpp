#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cout << "Введите кол-во лекций: ";
    cin >> N;
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cout << "Введите начало и конец лекции: ";
        cin >> lectures[i].first >> lectures[i].second;
    }
    sort(lectures.begin(), lectures.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });
    int count = 0;
    int last_end = 0;
    for (const auto& lecture : lectures) {
        if (lecture.first >= last_end) {
            count++;
            last_end = lecture.second;
        }
    }
    cout << "Максимальное количество заявок, которые можно выполнить: " << count;
}
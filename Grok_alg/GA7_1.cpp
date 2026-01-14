#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> lectures(N);

    for (int i = 0; i < N; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    // сортировка по времени окончания
    sort(lectures.begin(), lectures.end(),
         [](auto &a, auto &b) {
             return a.second < b.second;
         });

    int count = 0;
    int last_end = 0;

    for (auto &lec : lectures) {
        if (lec.first >= last_end) {
            count++;
            last_end = lec.second;
        }
    }

    cout << count;
    return 0;
}

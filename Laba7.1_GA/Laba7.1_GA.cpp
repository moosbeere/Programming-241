#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].second >> lectures[i].first; // (конец, начало)
    }

    // Сортируем по времени окончания
    sort(lectures.begin(), lectures.end());

    int count = 0;
    int last_end = 0;

    for (int i = 0; i < N; i++) {
        if (lectures[i].second >= last_end) {
            count++;
            last_end = lectures[i].first;
        }
    }

    cout << count << endl;

    return 0;
}
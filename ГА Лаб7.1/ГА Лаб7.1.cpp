#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].second >> lectures[i].first;
    }

    sort(lectures.begin(), lectures.end());

    int count = 0;
    int last_end = 0;

    for (const auto& lecture : lectures) {
        int start = lecture.second;
        int end = lecture.first;

        if (start >= last_end) {
            count++;
            last_end = end;
        }
    }

    cout << count << endl;

    return 0;
}
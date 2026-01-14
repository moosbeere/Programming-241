#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].first >> boxes[i].second; // wi, ci
    }

    // сортируем по (wi + ci)
    sort(boxes.begin(), boxes.end(),
         [](auto &a, auto &b) {
             return a.first + a.second < b.first + b.second;
         });

    const long long INF = numeric_limits<long long>::max();
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        long long w = boxes[i].first;
        long long c = boxes[i].second;

        for (int k = answer + 1; k >= 1; k--) {
            if (dp[k - 1] <= c && dp[k - 1] + w < dp[k]) {
                dp[k] = dp[k - 1] + w;
                answer = max(answer, k);
            }
        }
    }

    cout << answer;
    return 0;
}

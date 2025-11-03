#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }

    sort(boxes.begin(), boxes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first + a.second) < (b.first + b.second);
        });

    priority_queue<int> pq;
    long long totalWeight = 0;

    for (const auto& box : boxes) {
        int weight = box.first;
        int capacity = box.second;

        if (totalWeight <= capacity) {
            pq.push(weight);
            totalWeight += weight;
        }
        else if (!pq.empty() && pq.top() > weight) {
            totalWeight -= pq.top();
            pq.pop();
            pq.push(weight);
            totalWeight += weight;
        }
    }

    cout << pq.size() << endl;

    return 0;
}
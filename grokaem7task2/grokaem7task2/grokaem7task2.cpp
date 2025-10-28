#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cin >> n;

    vector<pair<int, int>> boxes(n);

    for (int i = 0; i < n; i++) {
        int w, c;
        cin >> w >> c;
        boxes[i] = { c, w }; 
    }
    sort(boxes.begin(), boxes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first + a.second) < (b.first + b.second);
        });

    long long total_weight = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int weight = boxes[i].second;
        int capacity = boxes[i].first;

        if (capacity >= total_weight) {
            count++;
            total_weight += weight;
        }
    }

    cout << count << endl;

    return 0;
}
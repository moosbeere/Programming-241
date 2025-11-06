#include <iostream>
#include <vector>
#include <algorithm>

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

    long long total_weight = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (total_weight <= boxes[i].second) {
            count++;
            total_weight += boxes[i].first;
        }
    }

    cout << count << endl;

    return 0;
}
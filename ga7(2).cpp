#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Box {
    long long weight;
    long long capacity;
};

int main() {
    (LC_ALL, "ru");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Box> boxes(n);

    for (int i = 0; i < n; i++) {
        cin >> boxes[i].weight >> boxes[i].capacity;
    }

    sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
        return (a.weight + a.capacity) < (b.weight + b.capacity);
        });

    long long totalWeight = 0;
    int maxCount = 0;

    multiset<long long> selectedWeights;

    for (const auto& box : boxes) {
        if (box.capacity >= totalWeight) {
            selectedWeights.insert(box.weight);
            totalWeight += box.weight;
            maxCount++;
        }
        else if (!selectedWeights.empty()) {
            auto it = prev(selectedWeights.end()); 
            if (*it > box.weight) {
                totalWeight -= *it;
                selectedWeights.erase(it);
                selectedWeights.insert(box.weight);
                totalWeight += box.weight;
            }
        }
    }

    cout << maxCount << "\n";

    return 0;
}
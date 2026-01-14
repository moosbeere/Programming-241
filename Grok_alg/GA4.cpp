#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> hashset;
    long long x;

    while (cin >> x) {
        if (x > 0) {
            hashset.insert((int)x);
        }
        else if (x < 0) {
            hashset.erase((int)(-x));
        }
        else { // x == 0
            vector<int> result(hashset.begin(), hashset.end());
            sort(result.begin(), result.end());

            for (int v : result)
                cout << v << " ";
            return 0;
        }
    }

    return 0;
}

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s;
    long long x;

    while (cin >> x) {
        if (x > 0) {
            s.insert((int)x);
        }
        else if (x < 0) {
            s.erase((int)(-x));
        }
        else {
            vector<int> result(s.begin(), s.end());
            sort(result.begin(), result.end());
            for (int num : result) {
                cout << num << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    return 0;
}

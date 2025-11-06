#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<int> set;
    int num;

    while (std::cin >> num) {
        if (num == 0) {
            break;
        }
        if (num > 0) {
            set.insert(num);
        }
        else {
            set.erase(-num);
        }
    }

    std::vector<int> result(set.begin(), set.end());
    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i + 1 < result.size()) {
            std::cout << " ";
        }
    }

    return 0;
}
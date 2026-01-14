#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <locale>

int main() {
    // Установка локали для корректной работы с русским языком
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::locale::global(std::locale("ru_RU.UTF-8"));

    std::unordered_set<long long> numbers;
    long long x;

    while (std::cin >> x) {
        if (x > 0) {
            numbers.insert(x);
        }
        else if (x < 0) {
            numbers.erase(-x);
        }
        else { // x == 0
            std::vector<long long> result(numbers.begin(), numbers.end());
            std::sort(result.begin(), result.end());

            for (size_t i = 0; i < result.size(); ++i) {
                std::cout << result[i];
                if (i + 1 < result.size())
                    std::cout << " ";
            }
            std::cout << std::endl;
            return 0;
        }
    }

    return 0;
}

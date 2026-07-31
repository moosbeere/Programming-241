#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  std::unordered_set<int> numbers;
  int num;

  while (std::cin >> num) {
    if (num == 0) {
      std::vector<int> sorted_numbers(numbers.begin(), numbers.end());
      std::sort(sorted_numbers.begin(), sorted_numbers.end());

      for (size_t i = 0; i < sorted_numbers.size(); ++i) {
        std::cout << sorted_numbers[i] << " ";
      }
      std::cout << std::endl;
      break;
    } else if (num > 0) {
      numbers.insert(num);
    } else {
      numbers.erase(-num);
    }
  }

  return 0;
}
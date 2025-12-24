#include <iostream>
#include <set>

int main() {
  std::set<long long> numbers;

  long long num;

  while (std::cin >> num) {
    if (num > 0) {
      numbers.insert(num);
    } else if (num < 0) {
      numbers.erase(-num);
    } else {
      for (long long n : numbers) {
        std::cout << n << ' ';
      }
      std::cout << '\n';

      break;
    }
  }

  return 0;
}

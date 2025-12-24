#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Lecture {
  int start;
  int end;

  bool operator<(const Lecture &other) const { return end < other.end; }
};

struct Box {
  int weight;
  int capacity;

  bool operator<(const Box &other) const {
    if (weight + capacity != other.weight + other.capacity) {
      return weight + capacity < other.weight + other.capacity;
    }
    return weight < other.weight;
  }
};

int maxLectures(vector<Lecture> &lectures) {
  sort(lectures.begin(), lectures.end());

  int count = 0;
  int last_end = 0;
  for (const auto &lecture : lectures) {
    if (lecture.start >= last_end) {
      count++;
      last_end = lecture.end;
    }
  }

  return count;
}

int maxBoxes(vector<Box> &boxes) {
  sort(boxes.begin(), boxes.end());

  int n = boxes.size();
  vector<long long> dp(n + 1, LLONG_MAX);
  dp[0] = 0;

  int max_height = 0;

  for (int i = 0; i < n; i++) {
    for (int h = max_height; h >= 0; h--) {
      if (dp[h] != LLONG_MAX) {
        if (dp[h] <= boxes[i].capacity) {
          if (dp[h] + boxes[i].weight < dp[h + 1]) {
            dp[h + 1] = dp[h] + boxes[i].weight;
            max_height = max(max_height, h + 1);
          }
        }
      }
    }
  }

  return max_height;
}

int main() {
  int n1;
  cout << "Введите количество заявок: ";
  cin >> n1;

  vector<Lecture> lectures(n1);
  cout << "Введите " << n1 << " пар (начало, конец):\n";
  for (int i = 0; i < n1; i++) {
    cin >> lectures[i].start >> lectures[i].end;
  }

  int result1 = maxLectures(lectures);
  cout << "Максимальное количество лекций: " << result1 << "\n\n";

  int n2;
  cout << "Введите количество коробок: ";
  cin >> n2;

  vector<Box> boxes(n2);
  cout << "Введите " << n2 << " пар (вес, максимальная нагрузка):\n";
  for (int i = 0; i < n2; i++) {
    cin >> boxes[i].weight >> boxes[i].capacity;
  }

  int result2 = maxBoxes(boxes);
  cout << "Максимальная высота башни: " << result2 << "\n";

  return 0;
}

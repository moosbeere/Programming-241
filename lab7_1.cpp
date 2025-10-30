#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TimeSpan {
  int start;
  int end;
};

int compare(const void *x1, const void *x2) {
  auto a = (TimeSpan *)x1;
  auto b = (TimeSpan *)x2;
  return (a->end > b->end) - (a->end < b->end);
}

int main() {
  int n;
  cin >> n;

  int count = 1;
  vector<TimeSpan *> lections;

  int start, end;
  for (int i = 0; i < n; i++) {
    cin >> start >> end;
    TimeSpan *timespan = new TimeSpan();
    timespan->start = start;
    timespan->end = end;
    lections.push_back(timespan);
  }
  sort(lections.begin(), lections.end(), compare);

  int j = 0;
  for (int i = 0; i < n; i++) {
    if (lections[i]->start >= lections[j]->end) {
      count += 1;
      j = i;
    }
  }

  cout << count;

  return 0;
}

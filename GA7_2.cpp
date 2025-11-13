#include <algorithm>
#include <iostream>
#include <vector>
struct Box {
  int wi, ci;
};
int compare(const Box *x1, const Box *x2) {
  if (x1->ci == x2->ci)
    return (x1->wi > x2->wi) - (x1->wi < x2->wi);
  return (x1->ci > x2->ci) - (x1->ci < x2->ci);
}

using namespace std;
int main() {
  int n;
  cin >> n;

  vector<Box *> boxes;

  for (int i = 0; i < n; i++) {
    Box *box = new Box();
    cin >> box->wi >> box->ci;

    boxes.push_back(box);
  }
  sort(boxes.begin(), boxes.end(), compare);
  int current_weight = boxes[0]->ci;
  int count = 0;
  for (int i = 0; i < n; i++) {
    Box *box = boxes[i];
    if (current_weight - box->wi < 0)
      continue;

    current_weight -= box->wi;
    count += 1;
  }
  cout << count << endl;
}

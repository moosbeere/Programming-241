#include <iostream>
#include <queue>

using namespace std;

int main() {
  int array[11][11] = {
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
      {0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
      {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},

  };
  int req = 10;

  queue<int> queue;
  int parent[11];
  int visited[11];
  for (int i = 0; i < 11; i++) {
    visited[i] = 0;
    parent[i] = -1;
  }
  const int start = 8;
  visited[start] = 1;

  queue.push(start);
  while (!queue.empty()) {
    int node = queue.front();
    queue.pop();
    if (node == req)
      break;
    for (int n = 0; n < 11; n++) {
      if (array[node][n] == 1 && !visited[n]) {
        visited[n] = true;
        parent[n] = node;
        queue.push(n);
      }
    }
  }
  int response[11];
  for (int i = 0; i < 11; i++) {
    response[i] = -1;
  }
  int count = 0;
  for (int v = req; v != -1; v = parent[v]) {
    response[count++] = v;
  }

  cout << "Кратчайший путь: ";
  for (int i = count - 1; i >= 0; i--) {
    if (response[i] == 10) {
      cout << 'S';
    } else {
      cout << (char)('A' + response[i]);
    }
    if (i > 0) {
      cout << " -> ";
    }
  }
  cout << endl;

  return 0;
}

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, S, F;
  cin >> N >> S >> F;

  S--;
  F--;

  vector<vector<int>> graph(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
    }
  }

  vector<int> dist(N, INT_MAX);
  vector<bool> visited(N, false);

  dist[S] = 0;

  for (int i = 0; i < N; i++) {
    int min = -1;
    for (int j = 0; j < N; j++) {
      if (!visited[j] && (min == -1 || dist[j] < dist[min])) {
        min = j;
      }
    }

    if (min == -1 || dist[min] == INT_MAX) {
      break;
    }

    visited[min] = true;

    for (int j = 0; j < N; j++) {
      if (graph[min][j] != -1 && !visited[j]) {
        int newDist = dist[min] + graph[min][j];
        if (newDist < dist[j]) {
          dist[j] = newDist;
        }
      }
    }
  }

  if (dist[F] == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << dist[F] << endl;
  }

  return 0;
}

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cost(N);
  for (int i = 0; i < N; i++) {
    cin >> cost[i];
  }

  int M;
  cin >> M;

  vector<vector<int>> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> minCost(N, INT_MAX);
  vector<bool> visited(N, false);

  minCost[0] = 0;

  for (int i = 0; i < N; i++) {
    int min = -1;
    for (int j = 0; j < N; j++) {
      if (!visited[j] && (min == -1 || minCost[j] < minCost[min])) {
        min = j;
      }
    }

    if (min == -1 || minCost[min] == INT_MAX) {
      break;
    }

    visited[min] = true;

    for (int neighbor : graph[min]) {
      if (!visited[neighbor]) {
        int newCost = minCost[min] + cost[min];
        if (newCost < minCost[neighbor]) {
          minCost[neighbor] = newCost;
        }
      }
    }
  }

  if (minCost[N - 1] == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << minCost[N - 1] << endl;
  }

  return 0;
}

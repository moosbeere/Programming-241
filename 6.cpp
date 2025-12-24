#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int vertex;
  int distance;

  bool operator>(const Node &other) const { return distance > other.distance; }
};

int dijkstra1(const vector<vector<int>> &graph, int start, int end, int n) {
  vector<int> dist(n + 1, INT_MAX);
  vector<bool> visited(n + 1, false);

  dist[start] = 0;

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int u = current.vertex;

    if (visited[u])
      continue;
    visited[u] = true;

    for (int v = 1; v <= n; v++) {
      if (graph[u][v] != -1) {
        int weight = graph[u][v];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          pq.push({v, dist[v]});
        }
      }
    }
  }

  return (dist[end] == INT_MAX) ? -1 : dist[end];
}

int dijkstra2(int n, const vector<int> &prices,
              const vector<vector<int>> &roads, int m) {
  vector<int> cost(n + 1, INT_MAX);
  vector<bool> visited(n + 1, false);

  cost[1] = prices[1];

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({1, cost[1]});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int u = current.vertex;

    if (visited[u])
      continue;
    visited[u] = true;

    if (u == n) {
      return cost[n];
    }

    for (int v = 1; v <= n; v++) {
      if (roads[u][v]) {
        if (cost[u] != INT_MAX && cost[u] + prices[v] < cost[v]) {
          cost[v] = cost[u] + prices[v];
          pq.push({v, cost[v]});
        }
      }
    }
  }

  return -1;
}

int main() {
  int n1, s, f;
  cout << "Введите N, S, F: ";
  cin >> n1 >> s >> f;

  vector<vector<int>> graph1(n1 + 1, vector<int>(n1 + 1));

  cout << "Введите матрицу смежности (" << n1 << "x" << n1 << "):\n";
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n1; j++) {
      cin >> graph1[i][j];
    }
  }

  int result1 = dijkstra1(graph1, s, f, n1);
  cout << "Кратчайшее расстояние от " << s << " до " << f << ": " << result1
       << "\n\n";

  int n2;
  cout << "Введите количество городов N: ";
  cin >> n2;

  vector<int> prices(n2 + 1);
  cout << "Введите цены на бензин в " << n2 << " городах: ";
  for (int i = 1; i <= n2; i++) {
    cin >> prices[i];
  }

  int m;
  cout << "Введите количество дорог M: ";
  cin >> m;

  vector<vector<int>> roads(n2 + 1, vector<int>(n2 + 1, 0));

  cout << "Введите " << m << " пар городов (дорог):\n";
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    roads[a][b] = 1;
    roads[b][a] = 1;
  }

  int result2 = dijkstra2(n2, prices, roads, m);
  cout << "Минимальная стоимость пути из города 1 в город " << n2 << ": "
       << result2 << "\n";

  return 0;
}

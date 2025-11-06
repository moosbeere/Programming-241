#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

// Дейкстра для задачи 1
vector<int> dijkstra_distance(int n, int start, const vector<vector<int>>& graph) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (int u = 0; u < n; ++u) {
            if (graph[v][u] != -1) {
                int weight = graph[v][u];
                if (dist[v] + weight < dist[u]) {
                    dist[u] = dist[v] + weight;
                    pq.push({ dist[u], u });
                }
            }
        }
    }

    return dist;
}

int main() {
    setlocale(LC_ALL, "RU");


    srand(time(nullptr));

    // Генерация случайного графа
    int N = 5 + rand() % 6; // 5..10 вершин
    int S = rand() % N;
    int F = rand() % N;

    cout << "Случайный граф (" << N << " вершин), старт = " << S + 1 << ", финиш = " << F + 1 << "\n";

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) graph[i][j] = 0;
            else {
                int r = rand() % 4; // 25% шанс отсутствия ребра
                graph[i][j] = (r == 0) ? -1 : 1 + rand() % 10;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    vector<int> dist = dijkstra_distance(N, S, graph);
    if (dist[F] == INT_MAX) cout << "Нет пути между вершинами.\n";
    else cout << "Кратчайшее расстояние: " << dist[F] << "\n";

    return 0;
}
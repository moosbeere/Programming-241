#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cout << "¬ведите кол-во городов N (1<=N<=100): \n";
    cin >> N;
    vector<int> cost(N);
    cout << "—тоимость бензина в разных городах = \n";
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    int M;
    cout << "¬ведите кол-во дорог в стране: \n";
    cin >> M;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    for (int i = 0; i < M; i++) {
        int u, v;
        cout << "¬ведите города, которые соедин€ют дороги: \n";
        cin >> u >> v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[0] = 0;
    for (int i = 0; i < N; i++) {
        int minCity = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (minCity == -1 || dist[j] < dist[minCity])) {
                minCity = j;
            }
        }
        if (minCity == -1 || dist[minCity] == INF) {
            break;
        }
        visited[minCity] = true;
        for (int neighbor = 0; neighbor < N; neighbor++) {
            if (graph[minCity][neighbor] != INF) {
                int newCost = dist[minCity] + cost[minCity];
                if (newCost < dist[neighbor]) {
                    dist[neighbor] = newCost;
                }
            }
        }
    }
    if (dist[N - 1] == INF) {
        cout << -1;
    }
    else {
        cout << "—уммарна€ стоимость маршрута = " << dist[N - 1];
    }
}
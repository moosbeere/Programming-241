#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> price(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    int M;
    cin >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(N + 1, INT_MAX);
    vector<bool> visited(N + 1, false);

    dist[1] = 0;

    for (int i = 0; i < N; i++) {
        int minDist = INT_MAX;
        int u = -1;
        for (int j = 1; j <= N; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v : graph[u]) {
            int cost = price[u]; // стоимость проезда по дороге u -> v
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
            }
        }
    }

    if (dist[N] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dist[N] << endl;
    }

    return 0;
}
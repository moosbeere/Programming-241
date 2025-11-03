#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N, S, F;
    cin >> N >> S >> F;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist(N + 1, INT_MAX);
    vector<bool> visited(N + 1, false);

    dist[S] = 0;

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
        if (u == F) break;

        visited[u] = true;

        for (int v = 1; v <= N; v++) {
            if (!visited[v] && graph[u][v] != -1 && dist[u] != INT_MAX) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    if (dist[F] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dist[F] << endl;
    }

    return 0;
}
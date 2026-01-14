#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int N, S, F;
    cin >> N >> S >> F;
    S--; F--; // переход к 0-индексации

    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> g[i][j];

    const int INF = numeric_limits<int>::max();
    vector<int> dist(N, INF);
    vector<bool> used(N, false);

    dist[S] = 0;

    for (int step = 0; step < N; step++) {
        int v = -1;

        for (int i = 0; i < N; i++)
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;

        if (dist[v] == INF) break;
        used[v] = true;

        for (int to = 0; to < N; to++) {
            if (g[v][to] >= 0) {
                if (dist[to] > dist[v] + g[v][to] && dist[v] != INF) {
                    dist[to] = dist[v] + g[v][to];
                }
            }
        }
    }

    if (dist[F] == INF) cout << -1;
    else cout << dist[F];

    return 0;
}

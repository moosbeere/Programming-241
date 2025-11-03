#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cost(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
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

    vector<int> totalCost(N + 1, INT_MAX);
    vector<bool> visited(N + 1, false);

    totalCost[1] = cost[1];

    for (int i = 0; i < N; i++) {
        int minCost = INT_MAX;
        int u = -1;

        for (int j = 1; j <= N; j++) {
            if (!visited[j] && totalCost[j] < minCost) {
                minCost = totalCost[j];
                u = j;
            }
        }

        if (u == -1) break;
        if (u == N) break;

        visited[u] = true;

        for (int v : graph[u]) {
            if (!visited[v]) {
                int newCost = totalCost[u] + cost[v];
                if (newCost < totalCost[v]) {
                    totalCost[v] = newCost;
                }
            }
        }
    }

    if (totalCost[N] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << totalCost[N] << endl;
    }

    return 0;
}
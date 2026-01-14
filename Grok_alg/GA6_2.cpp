#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int main() {
    int N;
    cin >> N;

    vector<int> price(N);
    for (int i = 0; i < N; i++) cin >> price[i];

    int M;
    cin >> M;

    vector<vector<Edge>> g(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back({b, price[a]});
        g[b].push_back({a, price[b]});
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(N, INF);

    dist[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0}); // расстояние, вершина

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (auto &edge : g[v]) {
            int to = edge.to;
            int cost = edge.cost;

            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    if (dist[N-1] == INF) cout << -1;
    else cout << dist[N-1];

    return 0;
}

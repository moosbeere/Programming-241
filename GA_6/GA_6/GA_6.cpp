//ЗАДАНИЕ 1
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <limits>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    int N, S, F;
//    cin >> N >> S >> F;
//
//    vector<vector<int>> graph(N, vector<int>(N));
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cin >> graph[i][j];
//        }
//    }
//
//    const int INF = numeric_limits<int>::max();
//    vector<int> dist(N, INF);
//    dist[S - 1] = 0;
//
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push({ 0, S - 1 });
//
//    while (!pq.empty()) {
//        int current_dist = pq.top().first;
//        int u = pq.top().second;
//        pq.pop();
//
//        if (current_dist > dist[u]) continue;
//
//        for (int v = 0; v < N; ++v) {
//            if (graph[u][v] != -1) {
//                int weight = graph[u][v];
//                if (dist[u] + weight < dist[v]) {
//                    dist[v] = dist[u] + weight;
//                    pq.push({ dist[v], v });
//                }
//            }
//        }
//    }
//
//    if (dist[F - 1] == INF) cout << -1 << "\n";
//    else cout << dist[F - 1] << "\n";
//
//    return 0;
//}





//ЗАДАНИЕ 2
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cin >> N;

    vector<int> cost(N);
    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    int M;
    cin >> M;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(N, INF);
    dist[0] = cost[0]; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ cost[0], 0 });

    while (!pq.empty()) {
        auto [curr_cost, u] = pq.top();
        pq.pop();

        if (curr_cost > dist[u]) continue;
        if (u == N - 1) break; 

        for (int v : graph[u]) {
            int next_cost = curr_cost + cost[v];
            if (next_cost < dist[v]) {
                dist[v] = next_cost;
                pq.push({ next_cost, v });
            }
        }
    }

    if (dist[N - 1] == INF) cout << -1 << "\n";
    else cout << dist[N - 1] << "\n";

    return 0;
}
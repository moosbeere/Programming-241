#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>

using namespace std;

const int INF = INT_MAX;

int main() {
    setlocale(LC_ALL, "ru");

    int N, S, F;

    cout << "Введите N S F: ";
    cin >> N >> S >> F;

    S--;
    F--;

    vector<vector<int>> graph(N, vector<int>(N));

    cout << "Введите матрицу смежности (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist(N, INF);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, S });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) {
            continue;
        }

        for (int neighbor = 0; neighbor < N; neighbor++) {
            if (graph[current_vertex][neighbor] != -1 && graph[current_vertex][neighbor] >= 0) {
                int weight = graph[current_vertex][neighbor];
                int new_dist = current_dist + weight;

                if (new_dist < dist[neighbor]) {
                    dist[neighbor] = new_dist;
                    pq.push({ new_dist, neighbor });
                }
            }
        }
    }

    cout << "Результат: ";
    if (dist[F] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dist[F] << endl;
    }

    return 0;
}
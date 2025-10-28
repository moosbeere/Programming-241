#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>

using namespace std;

const int INF = INT_MAX;

int main() {
    setlocale(LC_ALL, "ru");

    int N;
    cout << "Введите количество городов: ";
    cin >> N;

    vector<int> cost(N + 1);
    cout << "Введите стоимость бензина в каждом городе: ";
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    int M;
    cout << "Введите количество дорог: ";
    cin >> M;

    vector<vector<int>> graph(N + 1);
    cout << "Введите дороги (по две цифры через пробел): " << endl;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> min_cost(N + 1, INF);
    min_cost[1] = cost[1];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ cost[1], 1 });

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_city = pq.top().second;
        pq.pop();

        if (current_cost > min_cost[current_city]) {
            continue;
        }

        for (int neighbor : graph[current_city]) {
            int new_cost = current_cost + cost[neighbor];

            if (new_cost < min_cost[neighbor]) {
                min_cost[neighbor] = new_cost;
                pq.push({ new_cost, neighbor });
            }
        }
    }

    cout << "Минимальная стоимость пути: ";
    if (min_cost[N] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << min_cost[N] << endl;
    }

    return 0;
}
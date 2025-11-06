#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Edge {
    int to;
};

// Дейкстра для задачи 2 (минимальная стоимость маршрута)
vector<int> dijkstra_cost(int N, const vector<int>& fuel_cost, const vector<vector<Edge>>& graph) {
    vector<int> dist(N, INT_MAX);
    dist[0] = 0; // стартовый город, не покупаем бензин перед стартом
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (auto edge : graph[v]) {
            int u = edge.to;
            int cost = fuel_cost[v]; // бак нужен для выхода из текущего города
            if (dist[v] + cost < dist[u]) {
                dist[u] = dist[v] + cost;
                pq.push({ dist[u], u });
            }
        }
    }

    return dist;
}

int main() {
    setlocale(LC_ALL, "RU");


    srand(time(nullptr));

    // Генерация случайной страны
    int N = 5 + rand() % 6; // 5..10 городов
    cout << "Случайная страна, городов: " << N << "\n";

    vector<int> fuel_cost(N);
    for (int i = 0; i < N; i++) {
        fuel_cost[i] = rand() % 10; // стоимость бензина 0..9
        cout << "Город " << i + 1 << ", цена бензина: " << fuel_cost[i] << "\n";
    }

    int M = N + rand() % N; // количество дорог
    vector<vector<Edge>> graph(N);
    cout << "Дороги:\n";
    for (int i = 0; i < M; i++) {
        int u = rand() % N;
        int v = rand() % N;
        while (v == u) v = rand() % N; // не соединяем город с самим собой

        // Проверяем, что дорога еще не добавлена
        bool exists = false;
        for (auto e : graph[u]) if (e.to == v) { exists = true; break; }
        if (!exists) {
            graph[u].push_back({ v });
            graph[v].push_back({ u });
            cout << u + 1 << " <-> " << v + 1 << "\n";
        }
    }

    vector<int> dist = dijkstra_cost(N, fuel_cost, graph);
    if (dist[N - 1] == INT_MAX) cout << "Невозможно добраться до последнего города.\n";
    else cout << "Минимальная стоимость маршрута: " << dist[N - 1] << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    int N;
    cin >> N;

    vector<int> price(N);
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    int M;
    cin >> M;

    vector<vector<pair<int, int>>> graph(N);

    for (int j = 0; j < M; j++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // преобразуем в индексы

        // Добавляем ребра в обе стороны с весом = цене бензина в городе отправления
        graph[u].push_back({ v, price[u] });
        graph[v].push_back({ u, price[v] });
    }

    vector<int> dist(N, numeric_limits<int>::max());
    dist[0] = 0; // начальный город

    // Приоритетная очередь: (расстояние, вершина)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Если это не актуальное расстояние, пропускаем
        if (current_dist > dist[u]) continue;

        // Если дошли до конечного города, можно выходить
        if (u == N - 1) break;

        // Обходим всех соседей
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            int new_dist = dist[u] + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({ new_dist, v });
            }
        }
    }
    cout << "Минимальное количество бензина на путь = " << (dist[N - 1] == numeric_limits<int>::max() ? -1 : dist[N - 1]) << endl;
}
/*
Тестовые данные:
4
10 20 30 40
3
1 2
2 3
3 4
Результат: 60
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>

using namespace std;

int main() {
    // Установка русской локали для корректного отображения текста
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите количество городов: ";
    cin >> N; // количество городов

    vector<int> fuel_cost(N);
    cout << "Введите стоимость бензина в каждом городе через пробел: ";
    for (int i = 0; i < N; i++) {
        cin >> fuel_cost[i];
    }

    int M;
    cout << "Введите количество дорог: ";
    cin >> M;

    vector<vector<int>> graph(N);
    cout << "Введите дороги в формате 'город1 город2' (по одной на строку):" << endl;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // перевод в 0-индексацию
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Дейкстра с priority_queue
    vector<int> min_cost(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    min_cost[0] = 0; // старт из первого города
    pq.push(make_pair(0, 0)); // {текущая стоимость, город}

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int current_cost = top.first;
        int u = top.second;

        if (current_cost > min_cost[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int next_cost = current_cost + fuel_cost[u]; // платим бензин в текущем городе
            if (next_cost < min_cost[v]) {
                min_cost[v] = next_cost;
                pq.push(make_pair(next_cost, v));
            }
        }
    }

    cout << "Минимальная стоимость пути: ";
    if (min_cost[N - 1] == INT_MAX) {
        cout << -1 << endl; // путь невозможен
    }
    else {
        cout << min_cost[N - 1] << endl;
    }

    return 0;
}

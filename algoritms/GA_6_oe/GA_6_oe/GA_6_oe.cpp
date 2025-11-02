//1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, S, F;
    cin >> N >> S >> F;


    if (N < 1 || N > 100) { // Проверка корректности входных данных
        cout << -1 << endl;
        return 0;
    }
    if (S < 1 || S > N || F < 1 || F > N) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            // Проверка на корректность весов
            if (graph[i][j] < -1 || graph[i][j] > 100) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // Проверка главной диагонали
    for (int i = 0; i < N; i++) {
        if (graph[i][i] != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> dist(N, INT_MAX);
    vector<bool> visited(N, false);
    dist[S - 1] = 0;

    for (int i = 0; i < N; i++) {
        int minDist = INT_MAX;
        int minVertex = -1;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minVertex = j;
            }
        }

        if (minVertex == -1) break;
        visited[minVertex] = true;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[minVertex][j] != -1) {
                if (dist[minVertex] + graph[minVertex][j] < dist[j]) {
                    dist[j] = dist[minVertex] + graph[minVertex][j];
                }
            }
        }
    }

    if (dist[F - 1] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dist[F - 1] << endl;
    }

    return 0;
}



//2
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Проверка количества городов
    if (N < 1 || N > 100) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        // Проверка стоимости бензина
        if (cost[i] < 0 || cost[i] > 100) {
            cout << -1 << endl;
            return 0;
        }
    }

    int M;
    cin >> M;

    // Проверка количества дорог
    if (M < 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> roads(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        // Проверка корректности номеров городов
        if (a < 1 || a > N || b < 1 || b > N || a == b) {
            cout << -1 << endl;
            return 0;
        }

        // Проверка на дубликаты дорог
        if (roads[a - 1][b - 1] == 1) {
            cout << -1 << endl;
            return 0;
        }

        roads[a - 1][b - 1] = 1;
        roads[b - 1][a - 1] = 1;
    }

    vector<int> totalCost(N, INT_MAX);
    vector<bool> visited(N, false);
    totalCost[0] = 0;

    for (int i = 0; i < N; i++) {
        int minCost = INT_MAX;
        int minCity = -1;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && totalCost[j] < minCost) {
                minCost = totalCost[j];
                minCity = j;
            }
        }

        if (minCity == -1) break;
        visited[minCity] = true;

        for (int j = 0; j < N; j++) {
            if (roads[minCity][j] == 1 && !visited[j]) {
                int newCost = totalCost[minCity] + cost[minCity];
                if (newCost < totalCost[j]) {
                    totalCost[j] = newCost;
                }
            }
        }
    }

    if (totalCost[N - 1] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << totalCost[N - 1] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int N, S, F;

    // Ввод числа вершин
    while (true) {
        cout << "Введите количество вершин (N от 1 до 100): ";
        cin >> N;
        if (N >= 1 && N <= 100) break;
        cout << "Неверное количество вершин! Попробуйте снова.\n";
    }

    // Ввод начальной вершины
    while (true) {
        cout << "Введите начальную вершину (0.." << N - 1 << "): ";
        cin >> S;
        if (S >= 0 && S < N) break;
        cout << "Неверный номер вершины! Попробуйте снова.\n";
    }

    // Ввод конечной вершины
    while (true) {
        cout << "Введите конечную вершину (0.." << N - 1 << "): ";
        cin >> F;
        if (F >= 0 && F < N) break;
        cout << "Неверный номер вершины! Попробуйте снова.\n";
    }

    // Ввод матрицы смежности
    vector<vector<int>> graph(N, vector<int>(N));
    cout << "Введите матрицу смежности (" << N << " строк по " << N << " чисел, -1 если ребра нет):\n";
    for (int i = 0; i < N; i++) {
        while (true) {
            cout << "Строка " << i << ": ";
            bool valid = true;
            for (int j = 0; j < N; j++) {
                cin >> graph[i][j];
                if ((i == j && graph[i][j] != 0) || graph[i][j] < -1 || graph[i][j] > 100) {
                    valid = false;
                }
            }
            if (valid) break;
            cout << "Некорректная строка! На диагонали должно быть 0, веса должны быть от 0 до 100 или -1.\n";
        }
    }

    // Алгоритм Дейкстры
    vector<int> dist(N, INT_MAX);
    vector<bool> used(N, false);
    dist[S] = 0;

    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (v == -1 || dist[v] == INT_MAX) break;

        used[v] = true;

        for (int to = 0; to < N; to++) {
            if (graph[v][to] != -1) {
                if (dist[to] > dist[v] + graph[v][to]) {
                    dist[to] = dist[v] + graph[v][to];
                }
            }
        }
    }

    if (dist[F] == INT_MAX)
        cout << "Кратчайшего пути нет (-1)\n";
    else
        cout << "Кратчайшее расстояние: " << dist[F] << "\n";

    return 0;
}

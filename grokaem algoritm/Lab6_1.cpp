#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void printArr(vector<vector<int>>& mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int N, S, F;
    cin >> N >> S >> F;
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    printArr(mat, N);
    vector<int> distance(N, numeric_limits<int>::max());
    distance[S - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, S - 1 });
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Пропускаем устаревшие записи
        if (current_dist > distance[u]) continue;

        // Обходим всех соседей вершины u
        for (int v = 0; v < N; v++) {
            if (mat[u][v] != -1) {  // Если есть ребро u->v
                int new_dist = distance[u] + mat[u][v];

                // Если нашли более короткий путь
                if (new_dist < distance[v]) {  // Добавлено условие сравнения
                    distance[v] = new_dist;
                    pq.push({ new_dist, v });
                }
            }
        }
    }
    cout << "Кратчайший путь до конечной вершины = " << (distance[F - 1] == numeric_limits<int>::max() ? -1 : distance[F - 1]) << endl;
}

/*
тестовые данные:
4 1 4
0 4 -1 -1
-1 0 2 6
-1 -1 0 2
-1 -1 -1 0
Результат: 8

3 1 3
0 5 -1
-1 0 -1
-1 -1 0
Результат: -1
*/
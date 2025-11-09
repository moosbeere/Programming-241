#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int main()
{
    setlocale(LC_ALL, "ru");
    int N, S, F;
    cout << "Количество вершин графа N (1 <= N <= 100) \n";
    cin >> N;
    cout << "Начальная вершина графа S (1 <= S): \n";
    cin >> S;
    cout << "Конечная вершина графа F (F <= N): \n";
    cin >> F;
    S--;
    F--;
    vector<vector<int>> graph(N, vector<int>(N));

    cout << "Введите матрицу смежности " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
            {
                graph[i][j] = INF;
            }
        }
    }

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[S] = 0;

    for (int i = 0; i < N; i++)
    {
        int minVertex = -1;
        for (int j = 0; j < N; j++)
        {
            if (!visited[j] && (minVertex == -1 || dist[j] < dist[minVertex]))
            {
                minVertex = j;
            }
        }
        if (minVertex == -1 || dist[minVertex] == INF)
        {
            break;
        }
        visited[minVertex] = true;

        for (int neighbor = 0; neighbor < N; neighbor++)
        {
            if (graph[minVertex][neighbor] != INF)
            {
                int newDist = dist[minVertex] + graph[minVertex][neighbor];
                if (newDist < dist[neighbor])
                {
                    dist[neighbor] = newDist;
                }
            }
        }
    }
    if (dist[F] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << "Кротчайший путь = " << dist[F];
    }
}
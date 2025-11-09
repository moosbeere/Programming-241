#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Количество городов N: ";
    cin >> n;
    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Стоимость бензина в " << i + 1 << " городе = ";
        cin >> cost[i];
    }
    int m;
    cout << "Количество M дорог в стране: ";
    cin >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Два города, которые " << i + 1 << " дорога соединяет: ";
        cin >> u >> v;
        u--; v--;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int minCity = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (minCity == -1 || dist[j] < dist[minCity]))
            {
                minCity = j;
            }
        }
        if (minCity == -1 || dist[minCity] == INF)
        {
            break;
        }
        visited[minCity] = true;
        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            if (graph[minCity][neighbor] != INF)
            {
                int newCost = dist[minCity] + cost[minCity];
                if (newCost < dist[neighbor])
                {
                    dist[neighbor] = newCost;
                }
            }
        }
    }
    if (dist[n - 1] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << "Стоимость маршрута = " << dist[n - 1];
    }
}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Простой алгоритм Дейкстры
int dijkstra(vector<vector<int>>& graph, int start, int end, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    
    dist[start] = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        if (dist[u] == INT_MAX) break;
        visited[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && !visited[v]) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }
    
    return (dist[end] == INT_MAX) ? -1 : dist[end];
}

int main() {
    cout << "Алгоритм Дейкстры" << endl;
    
    // Простой пример
    int n = 4;
    vector<vector<int>> graph(n, vector<int>(n, -1));
    
    // Заполняем граф
    graph[0][1] = 10;
    graph[0][2] = 3;
    graph[1][3] = 2;
    graph[2][3] = 1;
    
    int result = dijkstra(graph, 0, 3, n);
    cout << "Кратчайший путь: " << result << endl;
    
    return 0;
}

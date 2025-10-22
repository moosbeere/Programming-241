#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Простой BFS для лабиринта
vector<string> bfs(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == end) break;
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                q.push(i);
            }
        }
    }
    
    // Восстанавливаем путь
    vector<string> path;
    int current = end;
    while (current != -1) {
        path.push_back(to_string(current));
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    cout << "BFS поиск пути" << endl;
    
    // Простой граф 4x4
    int n = 4;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    
    // Создаем связи
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[0][2] = 1;
    
    vector<string> path = bfs(graph, 0, 3);
    
    cout << "Путь: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    return 0;
}

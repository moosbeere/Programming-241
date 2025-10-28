#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;
vector<char> bfs(unordered_map<char, vector<char>>& graph, char start, char end) {
    queue<char> q;
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent; 

    q.push(start);
    visited[start] = true;
    parent[start] = '\0';

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        if (current == end) {
            vector<char> path;
            for (char at = end; at != '\0'; at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (char neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return {};
}

int main() {
    setlocale(LC_ALL, "");

    unordered_map<char, vector<char>> graph = {
        {'S', {'A', 'B'}},
        {'A', {'S', 'C'}},
        {'B', {'S', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B', 'G'}},
        {'E', {'B', 'H'}},
        {'F', {'C', 'I'}},
        {'G', {'D', 'I'}},
        {'H', {'E', 'I'}},
        {'I', {'F', 'G', 'H'}}
    };

    char start = 'S';
    char end = 'I';

    vector<char> path = bfs(graph, start, end);

    if (!path.empty()) {
        cout << "Кратчайший путь из S в I: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " → ";
        }
        cout << endl;
        cout << "Длина пути: " << path.size() - 1 << " шаг(ов)." << endl;
    }
    else {
        cout << "Путь не найден!" << endl;
    }

    return 0;
}
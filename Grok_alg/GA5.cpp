#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

// Функция BFS для поиска кратчайшего пути
vector<char> bfs(char start, char end,
                 unordered_map<char, vector<char>>& graph) {

    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;

    queue<char> q;
    q.push(start);
    visited[start] = true;
    parent[start] = 0;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        if (current == end)
            break;

        for (char next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    // Восстанавливаем путь
    vector<char> path;
    if (!visited[end]) {
        return path; // пути нет
    }

    char cur = end;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {

    // Граф соединений комнат
    unordered_map<char, vector<char>> graph;

    graph['S'] = {'A', 'D', 'B'};
    graph['A'] = {'S'};
    graph['D'] = {'S', 'E'};
    graph['E'] = {'D', 'G'};
    graph['G'] = {'E', 'H'};
    graph['H'] = {'G', 'I'};
    graph['I'] = {'H', 'J'};
    graph['J'] = {'I', 'C'};
    graph['C'] = {'B', 'J'};
    graph['B'] = {'S', 'C'};

    char start = 'S';
    char finish = 'I';

    vector<char> path = bfs(start, finish, graph);

    if (path.empty()) {
        cout << "Путь не найден!" << endl;
    } else {
        cout << "Кратчайший путь от " << start << " до " << finish << ": ";
        for (char c : path) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

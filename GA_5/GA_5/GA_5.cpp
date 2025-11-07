#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


vector<string> bfs(const unordered_map<string, vector<string>>& graph, string start, string end) {
    unordered_map<string, string> parent; 
    queue<string> q;
    q.push(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            vector<string> path;
            for (string v = end; v != ""; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto& neighbor : graph.at(current)) {
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    return {}; 
}

int main() {
    setlocale(LC_ALL, "ru");

    unordered_map<string, vector<string>> maze{
        {"S", {"A", "B", "D"}},
        {"A", {"S", "F"}},
        {"B", {"S", "C", "D"}},
        {"C", {"B"}},
        {"D", {"S", "B", "G"}},
        {"E", {"F", "G"}},
        {"F", {"A", "E"}},
        {"G", {"D", "E", "H"}},
        {"H", {"G", "I"}},
        {"I", {"H", "J"}},
        {"J", {"I"}}
    };

    string start = "S";
    string end = "I";

    auto path = bfs(maze, start, end);

    if (path.empty()) {
        cout << "Путь не найден" << endl;
    }
    else {
        cout << "Кратчайший путь: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}
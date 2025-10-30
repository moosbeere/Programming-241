#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    unordered_map<string, vector<string>> maze = {
        {"S", {"A", "B", "D", "E"}},
        {"A", {"S"}},
        {"B", {"S", "C", "D"}},
        {"C", {"B", "J"}},
        {"D", {"S", "B", "G"}},
        {"E", {"S", "G"}},
        {"F", {"G", "H"}},
        {"G", {"D", "E", "F", "H", "J"}},
        {"H", {"F", "G", "I"}},
        {"I", {"H", "J"}},
        {"J", {"C", "G", "I"}}
    };

    string start = "S";
    string end = "I";

    queue<string> q;
    q.push(start);

    unordered_map<string, bool> visited;
    visited[start] = true;

    unordered_map<string, string> previous;
    previous[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        for (string neighbor : maze[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                previous[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    vector<string> path;
    string current = end;

    while (current != "") {
        path.push_back(current);
        current = previous[current];
    }

    reverse(path.begin(), path.end());

    cout << "Кратчайший путь из '" << start << "' в '" << end << "':" << endl;
    cout << "Длина пути: " << path.size() - 1 << " шагов" << endl;
    cout << "Маршрут: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}
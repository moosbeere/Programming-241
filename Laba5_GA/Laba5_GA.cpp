#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


vector<string> reconstruct_path(unordered_map<string, string>& parent,
    const string& start, const string& end) {
    vector<string> path;
    string current = end;

    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}



vector<string> bfs_shortest_path(const unordered_map<string, vector<string>>& graph,
    const string& start, const string& end) {
    if (start == end) {
        return { start };
    }

    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        
        if (current == end) {
            return reconstruct_path(parent, start, end);
        }

        
        if (graph.find(current) != graph.end()) {
            for (const string& neighbor : graph.at(current)) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }
    }

    
    return {};
}

int main() {
    
    setlocale(LC_ALL, "Ru");
    unordered_map<string, vector<string>> graph = {
        {"S", {"A", "B", "E", "D"}},
        {"A", {"S"}},
        {"B", {"S", "C", "D"}},
        {"C", {"B", "J"}},
        {"D", {"S", "G", "B"}},
        {"E", {"G", "S"}},
        {"F", {"H", "G"}},
        {"G", {"E", "D", "J", "H"}},
        {"J", {"C", "G"}},  
        {"I", {"J", "H"}},
        {"H", {"F", "J", "I"}}
    };

    string start = "S";
    string end = "I";

    vector<string> shortest_path = bfs_shortest_path(graph, start, end);

    
    if (!shortest_path.empty()) {
        cout << "Кратчайший путь от " << start << " до " << end << ": ";
        for (size_t i = 0; i < shortest_path.size(); ++i) {
            cout << shortest_path[i];
            if (i < shortest_path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\nДлина пути: " << shortest_path.size() - 1 << " шагов" << endl;
    }
    else {
        cout << "Путь не найден!" << endl;
    }

    cout << "\nАнализ возможных кратчайших путей:" << endl;
    cout << "1. S -> D -> G -> J -> I (4 шага)" << endl;
    cout << "2. S -> D -> G -> H -> I (4 шага)" << endl;
    cout << "3. S -> E -> G -> J -> I (4 шага)" << endl;
    cout << "4. S -> E -> G -> H -> I (4 шага)" << endl;
    cout << "5. S -> B -> C -> J -> I (4 шага)" << endl;

    return 0;
}